# Papera: a toy fully functioning Command and Control server

Papera is a minimal framework I built in order to learn how to build a minimal
but fully functional Command and Control server capable of managing dispatching
commands from multiple _controllers_ to multiple _victims_.

- `victim`: the computer that has been compromised and is secretly running
  commands that the _controller_ is giving.
- `controller`: the computer that is giving commands to the _victim_ computer.
  In order to give a command the _controller_ connects to a special socket saved
  in `/tmp` directory. Since there's one socket per victim, the _controller_ is
  able to send commands to multiple victims at the same time.

This toy example is designed to work on Mac OSX, but you can easily adapt it for
any other OS since the vector of attack is a keyboard.

# Anatomy of a compromise

## Vector of attack: simulated keyboard

The designed vector of attack is a custom made malicious USB stick, similar to
a [Rubber Ducky](https://shop.hak5.org/products/usb-rubber-ducky-deluxe), but
costs $3. I used a Digispark ATtiny85, you can see a complete tutorial
[here](https://maker.pro/arduino/projects/how-to-build-a-rubber-ducky-usb-with-arduino-using-a-digispark-module).

## Stage 1

The malicious USB is inserted in the machine and it pretends to be a keyboard.
As soon as it's plugged in an USB port it will start typing at superhuman speed
and will execute the following operations:

- open the `terminal` app
- fetch the `second-stage.sh` script using curl and executes it with in the
  background with `nohup`
- closes the terminal

Note that the `second-stage.sh` script will stay alive in the background thanks
to `nohup`.

Stage 1 script should be as simple as possible because should be typed (at super
human speed) by the malicious USB. The longer it takes, the longer the attack
takes to succeed.

## Stage 2

The `second-stage.sh` script is in charge of opening a permanent HTTP connection
to the Command and Control server and keep re-open it every time it ends. Every
time a `controller` sends a command through the HTTP connection, it will get
executed in bash.

## Command and Control server

The `controller` is expected to ssh in the Command and Control machine. Every
time the _Stage 2_ attack succeeds and an HTTP connection is established, a
socket is created in the `/tmp` directory in the format
`/tmp-<victim-ip>-<uuid>.sock`. The controller just needs to connect to the
socket with
`nc -U /tmp-<victim-ip>-<uuid>.sock`. If the _controller_ disconnects, the
socket stays open, waiting for a re-connection. If the _victim_ disconnects, the
_controller_ socket is closed.

To start the C&C server you just need to clone the repo on a cloud VM, open port
`1338` and make the machine accessible via SSH and run:

```
npm install
npm run start
```
