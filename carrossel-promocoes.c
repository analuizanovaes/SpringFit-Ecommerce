#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

/* ============================================================================
 * ESTRUTURA: LISTA DUPLAMENTE ENCADEADA CIRCULAR
 * Aplicação Prática: Vitrine de Ofertas (Carrossel)
 * ============================================================================ */

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
    
    printf("\n+------------------------------------------------+\n");
    printf("| [SISTEMA] Produto adicionado ao carrossel!     |\n");
    printf("+------------------------------------------------+\n");
}

void exibirCarrossel(NoDuplo* carrossel, int limiteIteracoes) {
    if (carrossel == NULL) {
        printf("\n+------------------------------------------------+\n");
        printf("| [AVISO] O carrossel de promocoes esta vazio!   |\n");
        printf("+------------------------------------------------+\n");
        return;
    }

    NoDuplo* atual = carrossel;
    int contador = 0;

    printf("\n+------------------------------------------------+\n");
    printf("|       CARROSSEL DE PROMOCOES SPRING FIT        |\n");
    printf("+------+------+------------------------+---------+\n");
    printf("| LOOP |  ID  | NOME DO PRODUTO        | PRECO   |\n");
    printf("+------+------+------------------------+---------+\n");
    
    while (contador < limiteIteracoes) {
        // Formatação alinhada (Giro, ID, Nome limitado a 20 chars, Preço)
        printf("| %-4d | %-4d | %-22.22s | R$ %-4.2f |\n", contador + 1, atual->produto.id, atual->produto.nome, atual->produto.preco);
        atual = atual->proximo; 
        contador++;
    }
    printf("+------+------+------------------------+---------+\n");
}

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

void removerDoCarrossel(NoDuplo** carrossel, int idRemover) {
    if (*carrossel == NULL) {
        printf("\n+------------------------------------------------+\n");
        printf("| [ERRO] Carrossel vazio. Remocao impossivel.    |\n");
        printf("+------------------------------------------------+\n");
        return;
    }

    NoDuplo* noRemover = buscarNoCarrossel(*carrossel, idRemover);

    if (noRemover == NULL) {
        printf("\n+------------------------------------------------+\n");
        printf("| [ERRO] Produto ID %-4d nao foi encontrado.     |\n", idRemover);
        printf("+------------------------------------------------+\n");
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
    printf("\n+------------------------------------------------+\n");
    printf("| [SISTEMA] Produto promocional foi removido!    |\n");
    printf("+------------------------------------------------+\n");
}
