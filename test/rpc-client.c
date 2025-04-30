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
    int a, b;
    char operacion;

    printf("Elige una operación: sumar (s), restar (r), multiplicar (m), dividir (d): ");
    scanf(" %c", &operacion); // espacio antes de %c para limpiar buffer
    printf("Introduce el primer número: ");
    scanf("%d", &a);
    printf("Introduce el segundo número: ");
    scanf("%d", &b);

     // Crear socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Configurar direcció del servidor
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Conectar amb el servidor
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Enviar operación y números
    write(sock, &operacion, sizeof(char));
    write(sock, &a, sizeof(int));
    write(sock, &b, sizeof(int));

    // Llegir el resultat
    int resultado;
    read(sock, &resultado, sizeof(int));

    // Mostrar el resultado
    printf("Resultado: %d\n", resultado);

    // Cerrar socket
    close(sock);
    return 0;
}
