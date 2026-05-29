# Listas Encadeadas em C
 
Dois programas implementados como exercícios de manipulação de listas encadeadas para a disciplina de Estrutura de Dados.
 
## lista_simples.c — Partes 1 a 4
 
### Parte 1 — Inserção em Posição Específica
Insere um valor em qualquer posição da lista (base 0). Percorre até o nó anterior à posição desejada e re-liga os ponteiros. Trata os casos de lista vazia, inserção no início, meio e fim, exibindo erro se a posição for inválida.
 
**Complexidade:** O(n) tempo, O(1) espaço.
 
### Parte 2 — Busca por Valor
Percorre a lista linearmente com um contador de posição. Retorna o índice da primeira ocorrência ou `-1` se o valor não for encontrado.
 
**Complexidade:** O(n) tempo, O(1) espaço.
 
### Parte 3 — Inverter Lista
Inverte a lista in-place usando três ponteiros (`anterior`, `atual`, `proximo`). A cada iteração re-liga `atual->prox` para trás, sem alocar memória adicional ou criar nova lista.
 
**Complexidade:** O(n) tempo, O(1) espaço.
 
### Parte 4 — Dividir Lista em Duas
Usa a técnica do ponteiro lento/rápido (*tortoise & hare*): o ponteiro rápido anda 2 nós por iteração enquanto o lento anda 1. Quando o rápido chega ao fim, o lento está na metade exata. Se ímpar, a primeira lista recebe o elemento extra.
 
**Complexidade:** O(n) tempo, O(1) espaço.
 
---
 
## playlist.c — Parte 5
 
### Playlist Circular Duplamente Encadeada
Gerencia uma playlist de músicas usando lista circular duplamente encadeada. Cada nó armazena o nome da música e possui ponteiros `prox` e `ant`. O último nó aponta para o primeiro e o primeiro aponta para o último, permitindo navegação bidirecional infinita.
 
- `adicionarMusica` — insere ao final re-ligando os ponteiros `prox` e `ant` para manter a circularidade.
- `proximaMusica` / `musicaAnterior` — avançam ou recuam o ponteiro corrente pelo círculo.
- `exibirPlaylist` — percorre uma volta completa usando `do-while` com o `head` como critério de parada.
- `totalMusicas` — conta os nós em uma volta completa.
- Controle de loop infinito na navegação feito via contador (`total * voltas`), evitando percurso indefinido.
**Complexidade:** O(1) por inserção/navegação, O(n) para exibição e contagem.