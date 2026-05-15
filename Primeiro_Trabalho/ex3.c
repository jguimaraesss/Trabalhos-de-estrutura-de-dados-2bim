#include <stdio.h>
#include <inttypes.h>
 
int64_t hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {                /* caso base */
        printf("Disco 1: %c -> %c\n", origem, destino);
        return 1;
    }
    int64_t mov = hanoi(n - 1, origem, auxiliar, destino);
    printf("Disco %d: %c -> %c\n", n, origem, destino);
    mov++;
    mov += hanoi(n - 1, auxiliar, destino, origem);
    return mov;
}
 
int main(void) {
    int n;
    printf("Numero de discos: ");
    scanf("%d", &n);
 
    if (n <= 0) {
        printf("Erro: n deve ser >= 1.\n");
        return 1;
    }
 
    int64_t total = hanoi(n, 'A', 'C', 'B');
    printf("\nTotal de movimentos: %" PRId64 " (2^%d - 1)\n", total, n);
    return 0;
}