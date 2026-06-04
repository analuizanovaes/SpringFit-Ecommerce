#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

/* ============================================================================
 * ESTRUTURA: LISTA DUPLAMENTE ENCADEADA (LDE)
 * Aplicação Prática: Catálogo de Produtos
 * ============================================================================ */

void inserirNoCatalogo(NoDuplo** catalogo, Produto novoProduto) {
    NoDuplo* novoNo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novoNo->produto = novoProduto;
    novoNo->anterior = NULL; 
    novoNo->proximo = *catalogo; 
    
    if (*catalogo != NULL) { 
        (*catalogo)->anterior = novoNo; 
    }
    *catalogo = novoNo;
    
    printf("\n+------------------------------------------------+\n");
    printf("| [SISTEMA] Produto inserido com sucesso!        |\n");
    printf("+------------------------------------------------+\n");
}

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
        // %-4d alinha o ID, %-23.23s alinha o nome, %-9.2f alinha o preço
        printf("| %-4d | %-23.23s | R$ %-10.2f |\n", atual->produto.id, atual->produto.nome, atual->produto.preco);
        ultimo = atual; 
        atual = atual->proximo; 
    }
    printf("+------+-------------------------+---------------+\n");

    printf("\n+------------------------------------------------+\n");
    printf("|          NAVEGACAO REVERSA (RETORNO)           |\n");
    printf("+------+-------------------------+---------------+\n");
    printf("|  ID  | NOME DO PRODUTO         | PRECO         |\n");
    printf("+------+-------------------------+---------------+\n");
    
    while (ultimo != NULL) {
        printf("| %-4d | %-23.23s | R$ %-10.2f |\n", ultimo->produto.id, ultimo->produto.nome, ultimo->produto.preco);
        ultimo = ultimo->anterior; 
    }
    printf("+------+-------------------------+---------------+\n");
}

NoDuplo* buscarNoCatalogo(NoDuplo* catalogo, int idBusca) {
    NoDuplo* atual = catalogo;
    while (atual != NULL) { 
        if (atual->produto.id == idBusca) {
            return atual; 
        }
        atual = atual->proximo;
    }
    return NULL; 
}

void removerDoCatalogo(NoDuplo** catalogo, int idRemover) {
    NoDuplo* noRemover = buscarNoCatalogo(*catalogo, idRemover);

    if (noRemover == NULL) {
        printf("\n+------------------------------------------------+\n");
        printf("| [ERRO] Produto ID %-4d nao foi encontrado.     |\n", idRemover);
        printf("+------------------------------------------------+\n");
        return;
    }

    if (noRemover->anterior != NULL) {
        noRemover->anterior->proximo = noRemover->proximo; 
    } else {
        *catalogo = noRemover->proximo;
    }

    if (noRemover->proximo != NULL) {
        noRemover->proximo->anterior = noRemover->anterior; 
    }

    free(noRemover);
    printf("\n+------------------------------------------------+\n");
    printf("| [SISTEMA] Produto removido do catalogo!        |\n");
    printf("+------------------------------------------------+\n");
}
