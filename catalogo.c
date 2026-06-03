#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

// 1. INSERÇÃO NO INÍCIO DA LISTA DUPLAMENTE ENCADEADA
// Utiliza ponteiro duplo (**) para alterar o endereço raiz da lista (passagem por referência).
void inserirNoCatalogo(NoDuplo** catalogo, Produto novoProduto) {
    // Alocação dinâmica de memória para o novo nó
    NoDuplo* novoNo = (NoDuplo*) malloc(sizeof(NoDuplo));

    // Atribuição dos dados ao novo nó
    novoNo->produto = novoProduto;
    novoNo->anterior = NULL; // Sendo o primeiro nó, o ponteiro de retrocesso é nulo

    // O ponteiro de avanço do novo nó aponta para a antiga raiz da lista
    novoNo->proximo = *catalogo; 

    // Se a lista já contiver elementos, o nó anterior da antiga raiz aponta para o novo nó
    if (*catalogo != NULL) { 
        (*catalogo)->anterior = novoNo; 
    }

    // Atualiza a raiz do catálogo para o novo nó recém-criado
    *catalogo = novoNo;
    printf("Produto '%s' inserido com sucesso!\n", novoProduto.nome);
}

// 2. EXIBIÇÃO E NAVEGAÇÃO BIDIRECIONAL
void exibirCatalogo(NoDuplo* catalogo) {
    if (catalogo == NULL) {
        printf("O catálogo está vazio!\n");
        return;
    }

    NoDuplo* atual = catalogo;
    NoDuplo* ultimo = NULL;

    printf("\n--- Navegação Direta (Avanço) ---\n");
    while (atual != NULL) {
        printf("ID: %d | %s | R$ %.2f\n", atual->produto.id, atual->produto.nome, atual->produto.preco);
        ultimo = atual; // Armazena a referência do último nó visitado para o retorno
        atual = atual->proximo; // Navega para o próximo nó
    }

    printf("\n--- Navegação Reversa (Retorno) ---\n");
    // Utiliza a referência 'ultimo' para percorrer a lista de trás para frente usando o ponteiro 'anterior'
    while (ultimo != NULL) {
        printf("ID: %d | %s | R$ %.2f\n", ultimo->produto.id, ultimo->produto.nome, ultimo->produto.preco);
        ultimo = ultimo->anterior; 
    }
}

// 3. BUSCA SEQUENCIAL POR ID
NoDuplo* buscarNoCatalogo(NoDuplo* catalogo, int idBusca) {
    NoDuplo* atual = catalogo;
    
    // Percorre a lista linearmente até encontrar o ID correspondente
    while (atual != NULL) { 
        if (atual->produto.id == idBusca) {
            return atual; // Retorna o endereço do nó encontrado
        }
        atual = atual->proximo;
    }
    return NULL; // Retorna nulo se o elemento não for encontrado
}

// 4. REMOÇÃO DE NÓ E LIBERAÇÃO DE MEMÓRIA
void removerDoCatalogo(NoDuplo** catalogo, int idRemover) {
    NoDuplo* noRemover = buscarNoCatalogo(*catalogo, idRemover);

    if (noRemover == NULL) {
        printf("Produto ID %d não encontrado para remoção.\n", idRemover);
        return;
    }

    // Reajuste de ponteiros para desconectar o nó a ser removido
    if (noRemover->anterior != NULL) {
        noRemover->anterior->proximo = noRemover->proximo; 
    } else {
        // Se o nó anterior é nulo, o nó a ser removido é a raiz da lista
        *catalogo = noRemover->proximo;
    }

    if (noRemover->proximo != NULL) {
        noRemover->proximo->anterior = noRemover->anterior; 
    }

    // Desalocação do espaço de memória do nó removido para evitar vazamento (memory leak)
    free(noRemover);
    printf("Produto removido do catálogo com sucesso!\n");
}
