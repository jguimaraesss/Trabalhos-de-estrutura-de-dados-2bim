#include <stdio.h>
#include <stdlib.h>
 
typedef struct No {
    int valor;
    struct No *prox;
} No;
 
No *criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro: falha na alocacao de memoria.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox  = NULL;
    return novo;
}
 
void exibirLista(No *head) {
    No *atual = head;
    while (atual) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}
 
void liberarLista(No **head) {
    No *atual = *head;
    while (atual) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *head = NULL;
}
 
void inserirPosicao(No **head, int valor, int posicao) {
    if (posicao < 0) {
        fprintf(stderr, "Erro: posicao invalida (%d).\n", posicao);
        return;
    }
 
    No *novo = criarNo(valor);
 
    if (posicao == 0) {
        novo->prox = *head;
        *head = novo;
        return;
    }
 
    No *anterior = *head;
    int i;
    for (i = 0; i < posicao - 1; i++) {
        if (!anterior) {
            fprintf(stderr, "Erro: posicao invalida (%d). Lista tem menos elementos.\n", posicao);
            free(novo);
            return;
        }
        anterior = anterior->prox;
    }
 
    if (!anterior) {
        fprintf(stderr, "Erro: posicao invalida (%d).\n", posicao);
        free(novo);
        return;
    }
 
    novo->prox     = anterior->prox;
    anterior->prox = novo;
}
 
/*PARTE 2: Busca por Valor
 Retorna posição da primeira ocorrência (base 0) ou -1 se ausente.*/

int buscarValor(No *head, int valor) {
    No *atual   = head;
    int posicao = 0;
 
    while (atual) {
        if (atual->valor == valor)
            return posicao;
        atual = atual->prox;
        posicao++;
    }
    return -1;
}
 
/*PARTE 3: Inverter Lista
 Apenas re-ligação de ponteiros, sem vetor auxiliar ou nova lista.*/
void inverterLista(No **head) {
    No *anterior = NULL;
    No *atual    = *head;
    No *proximo  = NULL;
 
    while (atual) {
        proximo     = atual->prox;
        atual->prox = anterior;
        anterior    = atual;
        atual       = proximo;
    }
    *head = anterior;
}
/*PARTE 4: Dividir Lista em Duas
Técnica do ponteiro lento/rápido.
Se ímpar, a primeira lista recebe o elemento extra.*/
void dividirLista(No *head, No **lista1, No **lista2) {
    if (!head) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }
 
    No *lento  = head;
    No *rapido = head->prox;
 
    while (rapido && rapido->prox) {
        lento  = lento->prox;
        rapido = rapido->prox->prox;
    }
 
    *lista1     = head;
    *lista2     = lento->prox;
    lento->prox = NULL;
}

int main(void) {
    printf("========================================\n");
    printf(" PARTE 1: Insercao em posicao especifica\n");
    printf("========================================\n");
 
    No *lista = NULL;
    inserirPosicao(&lista, 10, 0);
    inserirPosicao(&lista, 20, 1);
    inserirPosicao(&lista, 30, 2);
 
    printf("Lista original:  ");
    exibirLista(lista);
 
    inserirPosicao(&lista, 99, 1);
    printf("Inserir 99 na posicao 1: ");
    exibirLista(lista);
 
    inserirPosicao(&lista, 0, 0);
    printf("Inserir  0 na posicao 0: ");
    exibirLista(lista);
 
    inserirPosicao(&lista, 77, 99); 
    liberarLista(&lista);
 
    printf("\n========================================\n");
    printf(" PARTE 2: Busca por valor\n");
    printf("========================================\n");
 
    inserirPosicao(&lista, 10, 0);
    inserirPosicao(&lista, 20, 1);
    inserirPosicao(&lista, 30, 2);
 
    printf("Lista: ");
    exibirLista(lista);
    printf("Buscar 20: posicao %d\n", buscarValor(lista, 20)); 
    printf("Buscar 10: posicao %d\n", buscarValor(lista, 10)); 
    printf("Buscar 30: posicao %d\n", buscarValor(lista, 30)); 
    printf("Buscar 99: posicao %d\n", buscarValor(lista, 99)); 
 
    printf("\n========================================\n");
    printf(" PARTE 3: Inverter lista\n");
    printf("========================================\n");
 
    printf("Antes:  ");
    exibirLista(lista);
    inverterLista(&lista);
    printf("Depois: ");
    exibirLista(lista); 
    liberarLista(&lista);
 
    printf("\n========================================\n");
    printf(" PARTE 4: Dividir lista\n");
    printf("========================================\n");
 
    inserirPosicao(&lista, 10, 0);
    inserirPosicao(&lista, 20, 1);
    inserirPosicao(&lista, 30, 2);
    inserirPosicao(&lista, 40, 3);
    inserirPosicao(&lista, 50, 4);
 
    printf("Original (impar): ");
    exibirLista(lista);
 
    No *l1 = NULL, *l2 = NULL;
    dividirLista(lista, &l1, &l2);
    printf("Lista 1: "); exibirLista(l1); 
    printf("Lista 2: "); exibirLista(l2); 
    liberarLista(&l1);
    liberarLista(&l2);
 
    No *listaP = NULL;
    inserirPosicao(&listaP, 1, 0);
    inserirPosicao(&listaP, 2, 1);
    inserirPosicao(&listaP, 3, 2);
    inserirPosicao(&listaP, 4, 3);
 
    printf("\nOriginal (par): ");
    exibirLista(listaP);
 
    No *lp1 = NULL, *lp2 = NULL;
    dividirLista(listaP, &lp1, &lp2);
    printf("Lista 1: "); exibirLista(lp1); 
    printf("Lista 2: "); exibirLista(lp2); 
    liberarLista(&lp1);
    liberarLista(&lp2);
 
    return 0;
}