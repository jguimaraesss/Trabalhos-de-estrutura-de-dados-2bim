# Tabela Hash em C

Implementação de um sistema de dicionário utilizando tabela hash com tratamento de colisões por listas encadeadas para a disciplina de Estrutura de Dados.

## dicionario_hash.c

### Inserção de Palavras e Definições

Permite cadastrar uma palavra e sua definição no dicionário. A posição é calculada através da função hash e o novo elemento é inserido no início da lista encadeada correspondente. Em caso de colisão, múltiplos elementos são armazenados na mesma posição através do encadeamento.

**Complexidade:** O(1) em média, O(n) no pior caso.

### Busca de Palavras

Localiza uma palavra utilizando a mesma função hash empregada na inserção. Após calcular a posição, percorre a lista encadeada correspondente até encontrar a palavra ou atingir o final da lista.

**Complexidade:** O(1) em média, O(n) no pior caso.

### Remoção de Palavras

Remove uma palavra do dicionário ajustando os ponteiros da lista encadeada e liberando a memória alocada dinamicamente. Trata corretamente os casos de remoção no início, meio ou final da lista.

**Complexidade:** O(1) em média, O(n) no pior caso.

### Exibição da Tabela Hash

Percorre todas as posições da tabela exibindo os elementos armazenados em cada lista encadeada. Permite visualizar a distribuição dos dados e a ocorrência de colisões.

**Complexidade:** O(n).

### Estatísticas da Tabela

Calcula informações sobre o estado atual da estrutura:

* Quantidade de elementos armazenados
* Quantidade de colisões
* Fator de carga
* Maior lista encadeada

O fator de carga é obtido pela razão entre a quantidade de elementos e o tamanho da tabela.

**Complexidade:** O(n).

---

## Estruturas Utilizadas

### Tabela Hash

Implementada através de um vetor de ponteiros para listas encadeadas. Cada posição da tabela representa um índice calculado pela função hash.

### Lista Encadeada

Utilizada para tratamento de colisões por encadeamento separado (*separate chaining*). Quando duas ou mais palavras geram o mesmo índice, elas são armazenadas na mesma lista.

### Alocação Dinâmica

Os nós são criados utilizando `malloc` e removidos utilizando `free`, permitindo crescimento dinâmico da estrutura.

---

## Função Hash

A função hash utilizada realiza a soma dos valores ASCII dos caracteres da palavra e calcula o resto da divisão pelo tamanho da tabela.

Essa abordagem possui implementação simples e é adequada para fins didáticos, permitindo compreender o funcionamento básico das tabelas hash.