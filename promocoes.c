/* 
====================================================================================================================================================================================
 * Estrutura: Lista Circular Duplamente Encadeada
 * Para que o banner de promocoes nao 'quebre' ao chegar no fim, o ponteiro do ultimo produto aponta de volta para o primeiro, criando um anel de rotatividade infinita sem risco de apontar para NULL.
 ===================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "promocoes.h"

/* Insercao circular: Amarra as pontas do anel */
void inserir_promocao(NoDuplo** cabeca, Produto p) {
    NoDuplo* novo = (NoDuplo*)malloc(sizeof(NoDuplo));
    if (novo == NULL) return;
    novo->produto = p;

    if (*cabeca == NULL) {
        novo->proximo = novo; 
        novo->anterior = novo;
        *cabeca = novo;
    } else {
        NoDuplo* ultimo = (*cabeca)->anterior; // Facilita achar o ultimo no
        
        novo->proximo = *cabeca;
        novo->anterior = ultimo;
        
        ultimo->proximo = novo;
        (*cabeca)->anterior = novo;
    }
}

/* Simulacao visual. O laco for faz a engrenagem circular rodar N vezes */
void exibir_carrossel(NoDuplo* cabeca, int giros) {
    if (cabeca == NULL) {
        printf("| Nenhuma promocao ativa no carrossel.                               |\n");
        return;
    }
    
    NoDuplo* temp = cabeca;
    for (int i = 0; i < giros; i++) {
        float valorOriginal = temp->produto.preco * 1.3;
        printf("| [PROMO] %-30s | R$ %6.2f -> R$ %6.2f    |\n", 
               temp->produto.nome, valorOriginal, temp->produto.preco);
               
        temp = temp->proximo; 
    }
}

/* Operacao Fundamental: Remocao sem quebrar o ciclo infinito */
void remover_promocao(NoDuplo** cabeca, int id) {
    if (*cabeca == NULL) return;

    NoDuplo* temp = *cabeca;
    NoDuplo* ultimo = (*cabeca)->anterior;

    while (temp->produto.id != id) {
        if (temp->proximo == *cabeca) return; // Nao achou apos dar a volta
        temp = temp->proximo;
    }

    if (temp->proximo == *cabeca && temp->anterior == *cabeca) {
        *cabeca = NULL; // Era o ultimo sobrevivente
        free(temp);
        return;
    }

    if (temp == *cabeca) {
        ultimo->proximo = (*cabeca)->proximo;
        (*cabeca)->proximo->anterior = ultimo;
        *cabeca = (*cabeca)->proximo;
    } else {
        temp->anterior->proximo = temp->proximo;
        temp->proximo->anterior = temp->anterior;
    }

    free(temp);
}