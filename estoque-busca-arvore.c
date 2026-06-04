#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

/* ============================================================================
 * ESTRUTURA: ÁRVORE BINÁRIA DE BUSCA (BST - Binary Search Tree)
 * Aplicação Prática: Gestão de Estoque e Busca Rápida por ID
 * Comportamento: Nós menores que a raiz são alocados à esquerda; nós maiores
 * são alocados à direita. Permite busca com complexidade O(log n).
 * ============================================================================ */

// 1. INSERÇÃO ORDENADA (Alocação Recursiva)
// Retorna o ponteiro do nó atualizado para manter a integridade da árvore
NoArvore* inserirNaArvore(NoArvore* raiz, Produto novoProduto, int quantidade) {
    // Caso Base: Alcançou uma folha vazia, momento de instanciar o nó
    if (raiz == NULL) {
        NoArvore* novoNo = (NoArvore*) malloc(sizeof(NoArvore));
        novoNo->produto = novoProduto;
        novoNo->quantidadeEmEstoque = quantidade;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        
        printf("\n+------------------------------------------------+\n");
        printf("| [SISTEMA] Produto alocado no estoque (BST)!    |\n");
        printf("+------------------------------------------------+\n");
        return novoNo;
    }

    // Regra da BST: Valores menores à esquerda, maiores à direita
    if (novoProduto.id < raiz->produto.id) {
        raiz->esquerda = inserirNaArvore(raiz->esquerda, novoProduto, quantidade);
    } else if (novoProduto.id > raiz->produto.id) {
        raiz->direita = inserirNaArvore(raiz->direita, novoProduto, quantidade);
    } else {
        // Tratamento de colisão: ID já existe
        printf("\n+------------------------------------------------+\n");
        printf("| [ERRO] O ID %-4d ja esta cadastrado no estoque.|\n", novoProduto.id);
        printf("+------------------------------------------------+\n");
    }

    return raiz;
}

// 2. FUNÇÃO AUXILIAR DE TRAVESSIA (In-Order Traversal)
// Visita a subárvore esquerda, depois a raiz e, por fim, a subárvore direita.
// Isso garante a exibição dos IDs em ordem estritamente crescente.
void travessiaEmOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        travessiaEmOrdem(raiz->esquerda);
        
        // Formatação alinhada (ID, Nome limitado a 22 chars, Quantidade, Preço)
        printf("| %-4d | %-22.22s | %-5d | R$ %-7.2f |\n", 
               raiz->produto.id, raiz->produto.nome, raiz->quantidadeEmEstoque, raiz->produto.preco);
               
        travessiaEmOrdem(raiz->direita);
    }
}

// 2.1 EXIBIÇÃO DE ESTOQUE (Wrapper para a Interface Gráfica)
void exibirEstoque(NoArvore* raiz) {
    if (raiz == NULL) {
        printf("\n+------------------------------------------------+\n");
        printf("| [AVISO] O estoque do Spring Fit esta vazio!    |\n");
        printf("+------------------------------------------------+\n");
        return;
    }

    printf("\n+------------------------------------------------+\n");
    printf("|       RELATORIO DE ESTOQUE (ORDENADO POR ID)   |\n");
    printf("+------+------------------------+-------+--------+\n");
    printf("|  ID  | NOME DO PRODUTO        | QTD   | PRECO  |\n");
    printf("+------+------------------------+-------+--------+\n");
    
    // Dispara a recursividade que imprimirá as linhas da tabela
    travessiaEmOrdem(raiz);
    
    printf("+------+------------------------+-------+--------+\n");
}

// 3. PESQUISA BINÁRIA (Busca Rápida O(log n))
NoArvore* buscarNaArvore(NoArvore* raiz, int idBusca) {
    // Caso Base: Nó não encontrado ou ID correspondente localizado
    if (raiz == NULL || raiz->produto.id == idBusca) {
        return raiz;
    }

    // Se o ID buscado for menor, descarta a metade direita da árvore
    if (idBusca < raiz->produto.id) {
        return buscarNaArvore(raiz->esquerda, idBusca);
    }

    // Se o ID buscado for maior, descarta a metade esquerda da árvore
    return buscarNaArvore(raiz->direita, idBusca);
}

// 4. FUNÇÃO AUXILIAR PARA REMOÇÃO: Encontrar o Menor Valor (Sucessor)
NoArvore* encontrarMinimo(NoArvore* noAtual) {
    NoArvore* atual = noAtual;
    // O menor valor em uma BST sempre estará no extremo esquerdo
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

// 5. REMOÇÃO DE NÓ (Cobrindo cenários de 0, 1 e 2 filhos)
NoArvore* removerDaArvore(NoArvore* raiz, int idRemover) {
    if (raiz == NULL) {
        printf("\n+------------------------------------------------+\n");
        printf("| [ERRO] Produto ID %-4d nao foi encontrado.     |\n", idRemover);
        printf("+------------------------------------------------+\n");
        return raiz;
    }

    // Etapa 1: Navegar pela árvore até encontrar o nó alvo
    if (idRemover < raiz->produto.id) {
        raiz->esquerda = removerDaArvore(raiz->esquerda, idRemover);
    } else if (idRemover > raiz->produto.id) {
        raiz->direita = removerDaArvore(raiz->direita, idRemover);
    } 
    // Nó encontrado! Executar a lógica de remoção
    else {
        // Cenário 1 e 2: Nó Folha (0 filhos) ou apenas 1 filho
        if (raiz->esquerda == NULL) {
            NoArvore* noTemp = raiz->direita;
            free(raiz); // Liberação de memória
            printf("\n+------------------------------------------------+\n");
            printf("| [SISTEMA] Produto removido do estoque!         |\n");
            printf("+------------------------------------------------+\n");
            return noTemp;
        } else if (raiz->direita == NULL) {
            NoArvore* noTemp = raiz->esquerda;
            free(raiz);
            printf("\n+------------------------------------------------+\n");
            printf("| [SISTEMA] Produto removido do estoque!         |\n");
            printf("+------------------------------------------------+\n");
            return noTemp;
        }

        // Cenário 3: Nó possui 2 filhos
        // Identifica o sucessor in-order (menor valor da subárvore direita)
        NoArvore* noTemp = encontrarMinimo(raiz->direita);

        // Sobrescreve os dados do nó atual com os dados do sucessor
        raiz->produto = noTemp->produto;
        raiz->quantidadeEmEstoque = noTemp->quantidadeEmEstoque;

        // Remove o nó sucessor original da subárvore direita (que agora é folha ou tem 1 filho)
        // Reduzimos o Cenário 3 silenciosamente para o Cenário 1 ou 2
        raiz->direita = removerDaArvore(raiz->direita, noTemp->produto.id);
    }
    
    return raiz;
}
