#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void serve_file(int client_sock, const char *file_path);

int main() {
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  char request[1024];

  // Create socket
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Bind socket to port
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(8080);
  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_sock, 5) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Server is running on port 8080\n");

  while (1) {
    // Accept incoming connection
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
      perror("accept");
      continue;
    }

    // Receive request from client
    recv(client_sock, request, sizeof(request), 0);
    printf("Received request:\n%s\n", request);

    if (strstr(request, "GET / HTTP")) {
      serve_file(client_sock, "/home/koniarch/Programming/C/projects/site/index.html");
    } else if (strstr(request, "GET /styles.css")) {
      serve_file(client_sock, "/home/koniarch/Programming/C/projects/site/styles.css");
    } else {
      const char *not_found = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 Not Found\n";
      send(client_sock, not_found, strlen(not_found), 0);
    }

    // Close client socket
    close(client_sock);
  }

  // Close server socket
  close(server_sock);

  return 0;
}

void serve_file(int client_sock, const char *file_path) {
  FILE *file = fopen(file_path, "r");
  if (file == NULL) {
    const char *not_found = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 Not Found\n";
    send(client_sock, not_found, strlen(not_found), 0);
    return;
  }

  // Determine file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for file content
  char *file_content = malloc(file_size + 1);
  if (file_content == NULL) {
    fclose(file);
    return;
  }

  // Read file content
  fread(file_content, 1, file_size, file);
  fclose(file);

  // Add null terminator
  file_content[file_size] = '\0';

  // Determine Content-Type based on file extension
  const char *content_type;
  if (strstr(file_path, ".html")) {
    content_type = "text/html; charset=UTF-8";
  } else if (strstr(file_path, ".css")) {
    content_type = "text/css; charset=UTF-8";
  } else {
    content_type = "text/plain; charset=UTF-8";
  }

  // Send HTTP response with file content
  char response[1024];
  snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\nContent-Type: %s\r\nContent-Length: %ld\r\n\r\n%s", content_type, file_size, file_content);
  send(client_sock, response, strlen(response), 0);

  free(file_content);
}

