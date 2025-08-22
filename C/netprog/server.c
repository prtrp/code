#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define  BUFFER_SIZE 1024

void die(const char* s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // create a socket fille descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) die("socket failed");

    // set socket option
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) die("setsockopt");

    // setup the server address
    // set hte address family to AF_INET (IPv4)
    address.sin_family = AF_INET;

    // accept connection from any available interface / communication mean
    address.sin_addr.s_addr = INADDR_ANY;

    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) die("bind fails");

    /* start listening for incoming connections */
    if (listen(server_fd, 3) < 0) die("listening fails");

    /* print that the server is listening */
    printf("server listening on port %d\n", PORT);

    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) die("Accept");

    printf("connection accepted\n");


    /* read data from the client and print it
     * decalre a signed size type variable for the number of bytes read */

    ssize_t valread;
    while ((valread = read(new_socket, buffer, BUFFER_SIZE)) >= 0) {
        printf("Client: %s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    /* close the socket */
    close(server_fd);
    return 0;
}
