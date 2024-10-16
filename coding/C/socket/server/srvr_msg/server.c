#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  const char server_message[256] = "ciao come stai";
  struct sockaddr_in server_addr;
  int serv_fd = 0;
  int client_fd = 0;

  if((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("ERROR SOCKET");
    exit(EXIT_FAILURE);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr=INADDR_ANY;

  if(bind(serv_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("ERROR BIDING");
    exit(EXIT_FAILURE);
  }

  if(listen(serv_fd, 5) < 0){
    perror("LISTEN FAILED");
    close(serv_fd);
    exit(EXIT_FAILURE);
  }

  if((client_fd = accept(serv_fd, NULL, NULL)) < 0) {
    perror("ERROR CLIENT_SK");
    close(serv_fd);
    exit(EXIT_FAILURE);
  }
  send(client_fd, &server_message, 256, 0);
  close(serv_fd);

  return 0;

}
