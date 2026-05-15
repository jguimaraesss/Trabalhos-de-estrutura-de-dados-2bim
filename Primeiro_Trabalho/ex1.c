#include <stdio.h>
#include <inttypes.h>
 
int64_t fibonacci(int n, int64_t *calls) {
    (*calls)++;  
 
    if (n <= 1)
        return n;
    return fibonacci(n - 1, calls) + fibonacci(n - 2, calls);
}
 
int main(void) {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
 
    if (n < 0) {
        printf("Erro: n deve ser >= 0.\n");
        return 1;
    }
 
    int64_t calls = 0;
    int64_t resultado = fibonacci(n, &calls);
 
    printf("\nFibonacci(%d) = %" PRId64 "\n", n, resultado);
    printf("Total de chamadas recursivas: %" PRId64 "\n", calls);
    printf("\n[Nota: para n=%d, a versao ingenua faz ~2^n chamadas]\n", n);
 
    return 0;
}