#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

/* ============================================================================
 * ESTRUTURA: LISTA DUPLAMENTE ENCADEADA (LDE)
 * Aplicação Prática: Catálogo de Produtos
 * Comportamento: Cada nó armazena uma referência para o sucessor (proximo) 
 * e para o predecessor (anterior), permitindo navegação bidirecional linear.
 * ============================================================================ */

// 1. INSERÇÃO NO INÍCIO DA LISTA (Head Insertion)
void inserirNoCatalogo(NoDuplo** catalogo, Produto novoProduto) {
    // Aloca memória para a criação de um novo componente da lista
    NoDuplo* novoNo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novoNo->produto = novoProduto;
    
    // Por ser inserido no início, não há nó anterior a ele
    novoNo->anterior = NULL; 

    // O novo nó aponta para a raiz atual da lista
    novoNo->proximo = *catalogo; 
    
    // Se a lista não estiver vazia, a raiz atual passa a apontar para trás (para o novo nó)
    if (*catalogo != NULL) { 
        (*catalogo)->anterior = novoNo; 
    }

    // Atualiza a referência principal do catálogo para o nó recém-criado
    *catalogo = novoNo;
    
    printf("\n+------------------------------------------------+\n");
    printf("| [SISTEMA] Produto inserido com sucesso!        |\n");
    printf("+------------------------------------------------+\n");
}

// 2. TRAVESSIA BIDIRECIONAL (Exibição Linear)
void exibirCatalogo(NoDuplo* catalogo) {
    if (catalogo == NULL) {
        printf("\n+------------------------------------------------+\n");
        printf("| [AVISO] O catalogo de produtos esta vazio!     |\n");
        printf("+------------------------------------------------+\n");
        return;
    }

    NoDuplo* atual = catalogo;
    NoDuplo* ultimo = NULL;

    printf("\n+------------------------------------------------+\n");
    printf("|           NAVEGACAO DIRETA (AVANCO)            |\n");
    printf("+------+-------------------------+---------------+\n");
    printf("|  ID  | NOME DO PRODUTO         | PRECO         |\n");
    printf("+------+-------------------------+---------------+\n");
    
    while (atual != NULL) {
        // Formatação com limite de caracteres para manter a tabela perfeitamente alinhada
        printf("| %-4d | %-23.23s | R$ %-10.2f |\n", atual->produto.id, atual->produto.nome, atual->produto.preco);
        
        ultimo = atual; // Guarda a referência do nó atual antes de pular para o próximo
        atual = atual->proximo; 
    }
    printf("+------+-------------------------+---------------+\n");

    printf("\n+------------------------------------------------+\n");
    printf("|          NAVEGACAO REVERSA (RETORNO)           |\n");
    printf("+------+-------------------------+---------------+\n");
    printf("|  ID  | NOME DO PRODUTO         | PRECO         |\n");
    printf("+------+-------------------------+---------------+\n");
    
    // Utiliza a variável 'ultimo' resgatada do laço anterior para percorrer a lista de trás para frente
    while (ultimo != NULL) {
        printf("| %-4d | %-23.23s | R$ %-10.2f |\n", ultimo->produto.id, ultimo->produto.nome, ultimo->produto.preco);
        ultimo = ultimo->anterior; 
    }
    printf("+------+-------------------------+---------------+\n");
}

// 3. BUSCA SEQUENCIAL (Busca Linear)
NoDuplo* buscarNoCatalogo(NoDuplo* catalogo, int idBusca) {
    NoDuplo* atual = catalogo;
    
    // Varredura linear: percorre do primeiro ao último elemento até encontrar correspondência
    while (atual != NULL) { 
        if (atual->produto.id == idBusca) {
            return atual; 
        }
        atual = atual->proximo;
    }
    return NULL; // Retorna nulo indicando que o conjunto percorrido não contém o ID
}

// 4. REMOÇÃO E MANUTENÇÃO DE PONTEIROS DUPLOS
void removerDoCatalogo(NoDuplo** catalogo, int idRemover) {
    // Isola o nó que será removido utilizando a função de busca
    NoDuplo* noRemover = buscarNoCatalogo(*catalogo, idRemover);

    if (noRemover == NULL) {
        printf("\n+------------------------------------------------+\n");
        printf("| [ERRO] Produto ID %-4d nao foi encontrado.     |\n", idRemover);
        printf("+------------------------------------------------+\n");
        return;
    }

    // Reajuste 1: Desconecta a referência do nó predecessor
    if (noRemover->anterior != NULL) {
        noRemover->anterior->proximo = noRemover->proximo; 
    } else {
        // Se não possui anterior, trata-se do primeiro nó. A raiz deve ser deslocada.
        *catalogo = noRemover->proximo;
    }

    // Reajuste 2: Desconecta a referência do nó sucessor
    if (noRemover->proximo != NULL) {
        noRemover->proximo->anterior = noRemover->anterior; 
    }

    // Auditoria de Memória: Liberação obrigatória do espaço alocado
    free(noRemover);
    
    printf("\n+------------------------------------------------+\n");
    printf("| [SISTEMA] Produto removido do catalogo!        |\n");
    printf("+------------------------------------------------+\n");
}
