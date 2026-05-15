#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int64_t fib_memo(int n, int64_t *memo, int64_t *calls) {
    (*calls)++;
 
    if (n <= 1)                  
        return n;
 
    if (memo[n] != -1)           
        return memo[n];
 
    memo[n] = fib_memo(n - 1, memo, calls)
            + fib_memo(n - 2, memo, calls);
    return memo[n];
}
 
int main(void) {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
 
    if (n < 0) {
        printf("Erro: n deve ser >= 0.\n");
        return 1;
    }
 
    int64_t *memo = (int64_t *) malloc((n + 1) * sizeof(int64_t));
    if (memo == NULL) {
        printf("Erro: falha na alocacao de memoria.\n");
        return 1;
    }
    for (int i = 0; i <= n; i++)
        memo[i] = -1;
 
    int64_t calls = 0;
    int64_t resultado = fib_memo(n, memo, &calls);
    int64_t calls_naive = ((int64_t)1 << (n + 1)) - 1;
 
    printf("\nFibonacci(%d) = %" PRId64 "\n", n, resultado);
    printf("Chamadas (memoizada): %" PRId64 "\n", calls);
    printf("Chamadas (ingenua):   %" PRId64 "\n", calls_naive);
    printf("Reducao: %.1f%%\n",
           100.0 * (1.0 - (double)calls / (double)calls_naive));
 
    free(memo);
    return 0;
}