#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

/* ============================================================================
 * ESTRUTURA: LISTA DUPLAMENTE ENCADEADA CIRCULAR
 * Aplicação Prática: Vitrine de Ofertas (Carrossel)
 * Comportamento: O último nó aponta de volta para o primeiro (próximo), 
 * e o primeiro aponta para o último (anterior), formando um anel contínuo.
 * ============================================================================ */

// 1. INSERÇÃO DE NÓ (Manutenção do Ciclo)
void inserirNoCarrossel(NoDuplo** carrossel, Produto novoProduto) {
    // Solicita ao sistema operacional a alocação dinâmica de espaço para o novo nó
    NoDuplo* novoNo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novoNo->produto = novoProduto;

    if (*carrossel == NULL) {
        // Caso Base: Lista vazia. O nó aponta para si mesmo, iniciando o anel.
        novoNo->proximo = novoNo;
        novoNo->anterior = novoNo;
        *carrossel = novoNo;
    } else {
        // Otimização: Em uma lista circular, o 'anterior' da raiz é sempre o último nó.
        // Isso permite acessar o final da lista sem precisar percorrer todos os itens.
        NoDuplo* ultimo = (*carrossel)->anterior;

        // O novo nó é posicionado entre o último nó existente e a raiz
        novoNo->proximo = *carrossel;
        novoNo->anterior = ultimo;
        
        // Os ponteiros dos nós vizinhos são reajustados para fechar a estrutura circular
        ultimo->proximo = novoNo;
        (*carrossel)->anterior = novoNo;
    }
    printf("  [+] Produto promocional '%s' adicionado ao carrossel!\n", novoProduto.nome);
}

// 2. EXIBIÇÃO DE DADOS (Travessia Circular com Trava)
void exibirCarrossel(NoDuplo* carrossel, int limiteIteracoes) {
    if (carrossel == NULL) {
        printf("  [!] O carrossel de promocoes esta vazio!\n");
        return;
    }

    NoDuplo* atual = carrossel;
    int contador = 0;

    printf("\n  --- Carrossel de Promocoes Spring Fit ---\n");
    // O contador previne o loop infinito inerente à estrutura de lista circular
    while (contador < limiteIteracoes) {
        printf("  [Giro %d] ID: %d | %s | R$ %.2f\n", contador + 1, atual->produto.id, atual->produto.nome, atual->produto.preco);
        
        // Ao chegar no último nó, o 'proximo' direciona a leitura automaticamente para a raiz
        atual = atual->proximo; 
        contador++;
    }
    printf("  -----------------------------------------\n");
}

// 3. BUSCA SEQUENCIAL EM ESTRUTURA FECHADA
NoDuplo* buscarNoCarrossel(NoDuplo* carrossel, int idBusca) {
    if (carrossel == NULL) return NULL;

    NoDuplo* atual = carrossel;
    
    // O laço do-while garante que a verificação passe pela raiz antes de avaliar a condição de parada
    do {
        if (atual->produto.id == idBusca) {
            return atual; // Retorna a referência de memória do nó encontrado
        }
        atual = atual->proximo;
    } while (atual != carrossel); // Condição de parada: o ponteiro completou uma volta inteira

    return NULL; // Retorna nulo se o ID não existir no ciclo
}

// 4. REMOÇÃO DE NÓ E PREVENÇÃO DE MEMORY LEAK (Vazamento de Memória)
void removerDoCarrossel(NoDuplo** carrossel, int idRemover) {
    if (*carrossel == NULL) {
        printf("  [!] Carrossel vazio, remocao impossivel.\n");
        return;
    }

    // Isola o nó que será removido utilizando a função de busca
    NoDuplo* noRemover = buscarNoCarrossel(*carrossel, idRemover);

    if (noRemover == NULL) {
        printf("  [!] Produto promocional ID %d nao encontrado.\n", idRemover);
        return;
    }

    if (noRemover->proximo == noRemover) {
        // Caso específico: Remoção do único nó restante na lista
        *carrossel = NULL;
    } else {
        // Redireciona os ponteiros dos nós vizinhos, efetivamente ignorando o nó alvo
        noRemover->anterior->proximo = noRemover->proximo;
        noRemover->proximo->anterior = noRemover->anterior;
        
        // Se o nó removido era a raiz, a raiz passa a ser o próximo nó da sequência
        if (*carrossel == noRemover) {
            *carrossel = noRemover->proximo;
        }
    }

    // Libera o bloco de memória dinâmica de volta para o sistema operacional
    free(noRemover); 
    printf("  [-] Produto promocional removido com sucesso!\n");
}
