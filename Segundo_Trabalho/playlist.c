#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;

No *criarNo(const char *nome) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro: falha na alocacao de memoria.\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (nome[i] != '\0' && i < 99) {
        novo->musica[i] = nome[i];
        i++;
    }
    novo->musica[i] = '\0';

    novo->prox = novo;
    novo->ant = novo;

    return novo;
}

void liberarPlaylist(No **head) {
    if (!*head) return;

    No *inicio = *head;
    No *atual = *head;

    do {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    } while (atual != inicio);

    *head = NULL;
}

/* Adiciona ao final mantendo circularidade */
void adicionarMusica(No **head, char *nome) {
    No *novo = criarNo(nome);

    if (!*head) {
        *head = novo;
        return;
    }

    No *ultimo = (*head)->ant;

    ultimo->prox = novo;
    novo->ant = ultimo;
    novo->prox = *head;
    (*head)->ant = novo;
}

/* Avança para próxima música */
void proximaMusica(No **atual) {
    if (*atual)
        *atual = (*atual)->prox;
}

/* Volta para música anterior */
void musicaAnterior(No **atual) {
    if (*atual)
        *atual = (*atual)->ant;
}

/* Exibe playlist completa */
void exibirPlaylist(No *head) {
    if (!head) {
        printf("Playlist vazia.\n");
        return;
    }

    No *atual = head;

    printf("Playlist: ");
    do {
        printf("[%s]", atual->musica);

        if (atual->prox != head)
            printf(" <-> ");

        atual = atual->prox;
    } while (atual != head);

    printf(" <-> (volta ao inicio)\n");
}

/* Conta músicas */
int totalMusicas(No *head) {
    if (!head) return 0;

    int count = 0;
    No *atual = head;

    do {
        count++;
        atual = atual->prox;
    } while (atual != head);

    return count;
}

int main(void) {
    printf("========================================\n");
    printf(" PARTE 5: Playlist Circular Dupla\n");
    printf("========================================\n");

    No *playlist = NULL;

    adicionarMusica(&playlist, "Rock");
    adicionarMusica(&playlist, "Jazz");
    adicionarMusica(&playlist, "Pop");

    printf("Total de musicas: %d\n", totalMusicas(playlist));
    exibirPlaylist(playlist);

    printf("\nNavegacao para frente (2 voltas):\n");

    No *atual = playlist;
    int total = totalMusicas(playlist);

    for (int i = 0; i < total * 2; i++) {
        printf("Tocando: %s\n", atual->musica);
        proximaMusica(&atual);
    }

    printf("\nNavegacao para tras (1 volta):\n");

    atual = playlist;

    for (int i = 0; i < total; i++) {
        printf("Tocando: %s\n", atual->musica);
        musicaAnterior(&atual);
    }

    No *ultimo = playlist->ant;

    printf("\nVerificacao de circularidade:\n");
    printf("Primeiro: %s\n", playlist->musica);
    printf("Ultimo: %s\n", ultimo->musica);
    printf("ultimo->prox == primeiro? %s\n",
           (ultimo->prox == playlist) ? "SIM" : "NAO");
    printf("primeiro->ant == ultimo? %s\n",
           (playlist->ant == ultimo) ? "SIM" : "NAO");

    liberarPlaylist(&playlist);

    printf("\nMemoria liberada.\n");

    return 0;
}