/* 
===============================================================================================================================================================================
 * Estrutura: Lista Duplamente Encadeada
 * Escolhemos a lista dupla para o catalogo porque, em um site real, o cliente precisa de botões 'Proximo' e 'Anterior'. O ponteiro duplo permite essa navegacao fluida na interface."
================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "catalogo.h"

/* Insere sempre no final da lista manipulando dois ponteiros */
void inserir_catalogo(NoDuplo** cabeca, Produto p) {
    NoDuplo* novo = (NoDuplo*)malloc(sizeof(NoDuplo));
    if (novo == NULL) return; 
    
    novo->produto = p;
    novo->proximo = NULL;

    if (*cabeca == NULL) {
        novo->anterior = NULL;
        *cabeca = novo;
        return;
    }

    NoDuplo* temp = *cabeca;
    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }
    
    temp->proximo = novo;
    novo->anterior = temp;
}

/* Varredura padrao O(n) */
void exibir_catalogo(NoDuplo* cabeca) {
    NoDuplo* temp = cabeca;
    if (temp == NULL) {
        printf("| O catalogo da loja encontra-se vazio no momento.                   |\n");
        return;
    }
    while (temp != NULL) {
        printf("| -> ID: %-5d | %-28s | R$ %8.2f          |\n", 
               temp->produto.id, temp->produto.nome, temp->produto.preco);
        temp = temp->proximo;
    }
}

/* Busca linear basica no catalogo */
NoDuplo* buscar_catalogo(NoDuplo* cabeca, int id) {
    NoDuplo* temp = cabeca;
    while (temp != NULL) {
        if (temp->produto.id == id) return temp;
        temp = temp->proximo;
    }
    return NULL;
}

/* Remove reconectando os fios: O 'anterior' liga no 'proximo' e vice-versa */
void remover_catalogo(NoDuplo** cabeca, int id) {
    if (*cabeca == NULL) return;

    NoDuplo* temp = *cabeca;
    while (temp != NULL && temp->produto.id != id) {
        temp = temp->proximo;
    }

    if (temp == NULL) return; // Protecao de ponteiro nulo

    // Desvio de ponteiros para isolar o no excluido
    if (*cabeca == temp) *cabeca = temp->proximo;
    if (temp->proximo != NULL) temp->proximo->anterior = temp->anterior;
    if (temp->anterior != NULL) temp->anterior->proximo = temp->proximo;

    free(temp); // Limpeza manual de memoria requerida em C
}