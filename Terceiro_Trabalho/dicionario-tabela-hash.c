#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct no{
    char palavra[50];
    char definicao[200];
    struct no *prox;
}No;

No *tabela[TAM];

void inicializar(){

    for(int i = 0; i < TAM; i++){
        tabela[i] = NULL;
    }
}

// Função responsável por transformar a palavra em uma posição da tabela
int hash(char palavra[]){

    int soma = 0;

    for(int i = 0; palavra[i] != '\0'; i++){
        soma += palavra[i];
    }

    return soma % TAM;
}

// Inserção utilizando lista encadeada para tratar colisões
void inserir(char palavra[], char definicao[]){

    int pos = hash(palavra);

    No *novo = (No*) malloc(sizeof(No));

    strcpy(novo->palavra, palavra);
    strcpy(novo->definicao, definicao);

    novo->prox = tabela[pos];
    tabela[pos] = novo;

    printf("Palavra cadastrada!\n");
}

// Busca da palavra na posição calculada pela função hash
void buscar(char palavra[]){

    int pos = hash(palavra);

    No *aux = tabela[pos];

    while(aux != NULL){

        if(strcmp(aux->palavra, palavra) == 0){

            printf("\nPalavra: %s\n", aux->palavra);
            printf("Definicao: %s\n", aux->definicao);

            return;
        }

        aux = aux->prox;
    }

    printf("Palavra nao encontrada!\n");
}

// Remoção do elemento e liberação da memória
void remover(char palavra[]){

    int pos = hash(palavra);

    No *aux = tabela[pos];
    No *ant = NULL;

    while(aux != NULL){

        if(strcmp(aux->palavra, palavra) == 0){

            if(ant == NULL){
                tabela[pos] = aux->prox;
            }else{
                ant->prox = aux->prox;
            }

            free(aux);

            printf("Palavra removida!\n");
            return;
        }

        ant = aux;
        aux = aux->prox;
    }

    printf("Palavra nao encontrada!\n");
}

// Exibe a distribuição dos elementos na tabela hash
void mostrarTabela(){

    for(int i = 0; i < TAM; i++){

        printf("[%d] ", i);

        No *aux = tabela[i];

        while(aux != NULL){

            printf("-> %s ", aux->palavra);
            aux = aux->prox;
        }

        printf("\n");
    }
}

// Cálculo das estatísticas exigidas pelo trabalho
void estatisticas(){

    int elementos = 0;
    int colisoes = 0;
    int maiorLista = 0;

    for(int i = 0; i < TAM; i++){

        int cont = 0;

        No *aux = tabela[i];

        while(aux != NULL){

            cont++;
            elementos++;

            aux = aux->prox;
        }

        if(cont > 1){
            colisoes += cont - 1;
        }

        if(cont > maiorLista){
            maiorLista = cont;
        }
    }

    printf("\n===== ESTATISTICAS =====\n");
    printf("Quantidade de elementos: %d\n", elementos);
    printf("Quantidade de colisoes: %d\n", colisoes);
    printf("Fator de carga: %.2f\n", (float)elementos / TAM);
    printf("Maior lista encadeada: %d\n", maiorLista);
}

int main(){

    inicializar();

    int op;

    char palavra[50];
    char definicao[200];

    do{

        printf("\n===== DICIONARIO =====\n");
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Remover\n");
        printf("4 - Mostrar tabela\n");
        printf("5 - Estatisticas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &op);
        getchar();

        switch(op){

            case 1:

                printf("Palavra: ");
                fgets(palavra, 50, stdin);
                palavra[strcspn(palavra, "\n")] = 0;

                printf("Definicao: ");
                fgets(definicao, 200, stdin);
                definicao[strcspn(definicao, "\n")] = 0;

                inserir(palavra, definicao);
                break;

            case 2:

                printf("Palavra: ");
                fgets(palavra, 50, stdin);
                palavra[strcspn(palavra, "\n")] = 0;

                buscar(palavra);
                break;

            case 3:

                printf("Palavra: ");
                fgets(palavra, 50, stdin);
                palavra[strcspn(palavra, "\n")] = 0;

                remover(palavra);
                break;

            case 4:
                mostrarTabela();
                break;

            case 5:
                estatisticas();
                break;

        }

    }while(op != 0);

    return 0;
}