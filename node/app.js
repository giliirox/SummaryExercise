

// Include Nodejs' net module.
const { type } = require('express/lib/response');
const Net = require('net');
// The port on which the server is listening.
const port = 8080;

// Use net.createServer() in your code. This is just for illustration purpose.
// Create a new TCP server.
const server = new Net.Server();
// The server listens to a socket for a client to make a connection request.
// Think of a socket as an end point.
server.listen(port, function() {
    console.log(`Server listening for connection requests on socket localhost:${port}`);
});

// When a client requests a connection with the server, the server creates a new
// socket dedicated to that client.
server.on('connection', function(socket) {
    console.log('A new connection has been established.');

    // Now that a TCP connection has been established, the server can send data to
    // the client by writing to its socket.
    socket.write('Hello, client.');

    // The server can also receive data from the client by reading from its socket.
    socket.on('data', function(chunk) {
        console.log(`Data received from client: ${chunk.toString()}`) 
        convertAndPrint(chunk);
    });

    // When the client requests to end the TCP connection with the server, the server
    // ends the connection.
    socket.on('end', function() {
        console.log('Closing connection with the client');
      
    });

    // Don't forget to catch error, for your own sake.
    socket.on('error', function(err) {
        console.log(`Error: ${err}`);
    });
});

function convertAndPrint(data) {
    console.log("in function")
    let mes={};
    mes.type= Buffer.from(data).readInt8(0);
    if( mes.type==1)
        {
        mes.status=Buffer.from(data).readInt8(2);
        console.log("=====================================")
        console.log(`type:${mes.type}`)
        console.log(`status:${mes.status}`)
        console.log("=====================================")
        }
    else
        {  
        mes.distance=Buffer.from(data).readFloatBE(2);
        mes.angle=Buffer.from(data).readFloatBE(6);
        mes.speed=Buffer.from(data).readFloatBE(10);
        console.log("=====================================")
        console.log(`type: ${mes.type}`)
        console.log(`distance: ${mes.distance}`)
        console.log(`angle: ${mes.angle}`)
        console.log(`speed: ${mes.speed} `)
        console.log("=====================================")
        }
   
}


