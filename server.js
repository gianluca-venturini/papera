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

app.listen(1337);

app.get('/', (req, res) => {
  // const fileName = req.socket.remoteAddress;
  const fileName = '/tmp/test.sock';
  try {
    fs.unlinkSync(fileName); // delete socket in case it's still there
  } catch (e) { }

  var server = net.createServer(stream => {
    stream.on('data', c => {
      console.log('data:', c.toString());
      res.write(c.toString());
    });
    stream.on('end', () => {
      server.close();
      res.end();
    });
  });

  server.listen(fileName);
});


// https.createServer(options, app).listen(1338);
http.createServer(options, app).listen(1338);
