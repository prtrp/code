# socket programming
the network programming itself is based on sockets. it means building a program that receives and transmits data between two or more computer by means of a network.
# socket:
is provided by default by any OS, provides a high level of abstraction for programmers so that we don't have to worry about underlying physical & software detail of network.
# 5 must know fundamentals
1. crating a socket (a socket descriptor). 
   Tcp sockets can be compared to a phone -> we need to call someone or accept their phone calls.
   
   To perform network I/O, the first thing a process must do this, call the socket function to create a specific type of socket by specifying the type of communication protocol, protocol family, etc..
```C
#include <sys/socket.h>
int socket(int domain, int type, int protocol);
```
2. Binding the socket
   register the socket to a port, provide a complete address for start communication, is like give to a phone his number. for allocate a port number to a socket.
   
   For be more technical we will be biding a socket that is inside our process to a address that contain both ip address and a port number. It means that is ready to receive/send information.
```C
#include <sys/socket.h>
int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);
```
3. Listen.
   Identify a bound, unconnected socket -> means "identify the connection request" listen for connection request.
   the process of converting an unconnected socket int a passive socket, indicate that the kernel should accept incoming connection requests directed to this socket.
```C
#include <sys/socket.h>
int listen(int sockfd, int backlog);
```
4. Accept connection request.
   transition of the connection request from listen() to an actual socket -> accept the connection request.
   After accepting the request (and automatic creation of the socket) the data can be transferred between the nodes.
```C
#include <sys/socket.h>
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```
5. connect
   attempting to establish a connection. Is like a dialing to a specific phone number. For make a connection request just specify the address to connect to and the socket descriptor to attach the socket to
```C
#include <sys/socket.h>
int connection(int sockfd, struct sockaddr *serv_addr, socklen_t addrlen);
```
