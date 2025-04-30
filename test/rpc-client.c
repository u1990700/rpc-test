// rpc-client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    int a = 5, b = 7;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    write(sock, &a, sizeof(int));
    write(sock, &b, sizeof(int));

    int resultado;
    read(sock, &resultado, sizeof(int));

    printf("Cliente: el resultado de %d + %d = %d\n", a, b, resultado);

    close(sock);
    return 0;
}
