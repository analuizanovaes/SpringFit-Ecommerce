#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

// 1. INSERÇÃO NO CARROSSEL (LISTA DUPLAMENTE ENCADEADA CIRCULAR)
void inserirNoCarrossel(NoDuplo** carrossel, Produto novoProduto) {
    NoDuplo* novoNo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novoNo->produto = novoProduto;

    if (*carrossel == NULL) {
        novoNo->proximo = novoNo;
        novoNo->anterior = novoNo;
        *carrossel = novoNo;
    } else {
        NoDuplo* ultimo = (*carrossel)->anterior;
        novoNo->proximo = *carrossel;
        novoNo->anterior = ultimo;
        ultimo->proximo = novoNo;
        (*carrossel)->anterior = novoNo;
    }
    printf("  [+] Produto promocional '%s' adicionado ao carrossel!\n", novoProduto.nome);
}

// 2. EXIBIÇÃO EM LOOP (SIMULAÇÃO DE CARROSSEL COM TRAVA DE LIMITE)
void exibirCarrossel(NoDuplo* carrossel, int limiteIteracoes) {
    if (carrossel == NULL) {
        printf("  [!] O carrossel de promocoes esta vazio!\n");
        return;
    }

    NoDuplo* atual = carrossel;
    int contador = 0;

    printf("\n  --- Carrossel de Promocoes Spring Fit ---\n");
    while (contador < limiteIteracoes) {
        printf("  [Giro %d] ID: %d | %s | R$ %.2f\n", contador + 1, atual->produto.id, atual->produto.nome, atual->produto.preco);
        atual = atual->proximo; 
        contador++;
    }
    printf("  -----------------------------------------\n");
}

// 3. BUSCA SEQUENCIAL NA LISTA CIRCULAR
NoDuplo* buscarNoCarrossel(NoDuplo* carrossel, int idBusca) {
    if (carrossel == NULL) return NULL;

    NoDuplo* atual = carrossel;
    do {
        if (atual->produto.id == idBusca) {
            return atual; 
        }
        atual = atual->proximo;
    } while (atual != carrossel); 

    return NULL; 
}

// 4. REMOÇÃO DE NÓ E MANUTENÇÃO DO CICLO
void removerDoCarrossel(NoDuplo** carrossel, int idRemover) {
    if (*carrossel == NULL) {
        printf("  [!] Carrossel vazio, remocao impossivel.\n");
        return;
    }

    NoDuplo* noRemover = buscarNoCarrossel(*carrossel, idRemover);

    if (noRemover == NULL) {
        printf("  [!] Produto promocional ID %d nao encontrado.\n", idRemover);
        return;
    }

    if (noRemover->proximo == noRemover) {
        *carrossel = NULL;
    } else {
        noRemover->anterior->proximo = noRemover->proximo;
        noRemover->proximo->anterior = noRemover->anterior;
        if (*carrossel == noRemover) {
            *carrossel = noRemover->proximo;
        }
    }

    free(noRemover); 
    printf("  [-] Produto promocional removido com sucesso!\n");
}
