# Recursão em C — Fibonacci e Torres de Hanói

Três programas implementados como exercícios de recursão para a disciplina de Algoritmos.

## Exercício 1 — Fibonacci Ingênuo (`ex1.c`)

Calcula o n-ésimo termo de Fibonacci recursivamente sem otimização. A cada chamada um contador é incrementado, evidenciando a ineficiência exponencial: para n=40 são feitas mais de 300 milhões de chamadas.

**Complexidade:** O(2ⁿ) tempo, O(n) espaço (pilha).

## Exercício 2 — Fibonacci com Memoização (`ex2.c`)

Mantém a recursão do exercício anterior, mas armazena resultados já calculados em um vetor alocado dinamicamente com `malloc`. Antes de calcular, verifica se `memo[n] != -1`; se sim, retorna o valor armazenado. O programa compara o número de chamadas das duas versões e exibe a redução percentual.

**Complexidade:** O(n) tempo, O(n) espaço.

## Exercício 3 — Torres de Hanói (`ex3.c`)

Resolve o problema recursivamente em três passos: move os n-1 discos menores para o pino auxiliar, move o disco maior para o destino e move os n-1 discos de volta. Lista cada movimento e retorna o total, que segue a fórmula 2ⁿ - 1.

**Complexidade:** O(2ⁿ) — ótimo para o problema, não há solução com menos movimentos.

## Compilação

```bash
gcc -o ex1 ex1.c && gcc -o ex2 ex2.c && gcc -o ex3 ex3.c
```
