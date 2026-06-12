# Tabela Hash em C

Implementação de um sistema de dicionário utilizando tabela hash com tratamento de colisões por listas encadeadas para a disciplina de Estrutura de Dados.

## dicionario_hash.c

### Inserção de Palavras e Definições

Permite cadastrar uma palavra e sua definição no dicionário. A posição é calculada através da função hash e o elemento é armazenado na tabela.

### Busca de Palavras

Localiza uma palavra cadastrada e exibe sua definição. A busca é realizada utilizando a mesma posição calculada pela função hash.

### Remoção de Palavras

Remove uma palavra do dicionário e libera a memória utilizada pelo elemento removido.

### Exibição da Tabela Hash

Mostra todas as posições da tabela e os elementos armazenados em cada uma delas.

### Estatísticas da Tabela

Exibe informações sobre a tabela:

- Quantidade de elementos armazenados
- Quantidade de colisões
- Fator de carga
- Maior lista encadeada

---

## Estruturas Utilizadas

### Tabela Hash

Implementada através de um vetor de ponteiros, onde cada posição representa um índice calculado pela função hash.

### Lista Encadeada

Utilizada para tratar colisões. Quando mais de uma palavra é armazenada na mesma posição da tabela, os elementos são organizados em uma lista encadeada.

### Alocação Dinâmica

Os elementos são criados utilizando `malloc` e removidos utilizando `free`, permitindo que a estrutura cresça conforme necessário.

---

## Função Hash

A função hash utilizada realiza a soma dos valores ASCII dos caracteres da palavra e calcula o resto da divisão pelo tamanho da tabela.

Essa abordagem foi escolhida por ser simples e adequada para demonstrar o funcionamento de uma tabela hash.


## Conclusão

O trabalho permitiu aplicar os conceitos estudados sobre tabelas hash e listas encadeadas, implementando um sistema capaz de armazenar, buscar e remover informações de forma organizada.

Além disso, foram utilizados recursos importantes da linguagem C, como structs, ponteiros e alocação dinâmica de memória.