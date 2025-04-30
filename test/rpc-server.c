// rpc-server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

int suma(int a, int b) {
    return a + b;
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    int opt = 1;
    int addrlen = sizeof(addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(12345);

    bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(server_fd, 1);

    printf("Servidor esperando conexiones en el puerto 12345...\n");

    client_fd = accept(server_fd, (struct sockaddr *)&addr, (socklen_t *)&addrlen);

    int a, b;
    read(client_fd, &a, sizeof(int));
    read(client_fd, &b, sizeof(int));

    printf("Servidor recibió: %d y %d\n", a, b);
    int resultado = suma(a, b);
    write(client_fd, &resultado, sizeof(int));

    close(client_fd);
    close(server_fd);
    return 0;
}
