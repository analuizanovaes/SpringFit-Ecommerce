/* =================================================================================================================================================================================
 * Estrutura: Arvore Binaria de Busca (BST)
 * Usamos a arvore para o estoque pois, diferentemente de uma lista onde a busca e O(n), na arvore dividimos o caminho pela metade a cada interacao, obtendo buscas super rapidas em O(log n).
=================================================================================================================================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include "estoque_bst.h"

/* Insere validando a regra da BST: menores a esquerda, maiores a direita */
NoArvore* inserir_bst(NoArvore* raiz, Produto p, int qtd) {
    if (raiz == NULL) {
        NoArvore* novo = (NoArvore*)malloc(sizeof(NoArvore));
        if (novo == NULL) return NULL; // Protecao de memoria
        novo->produto = p;
        novo->quantidadeEmEstoque = qtd;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    
    if (p.id < raiz->produto.id) {
        raiz->esquerda = inserir_bst(raiz->esquerda, p, qtd);
    } else if (p.id > raiz->produto.id) {
        raiz->direita = inserir_bst(raiz->direita, p, qtd);
    }
    return raiz;
}

/* Busca binaria com complexidade de tempo O(log n) */
NoArvore* buscar_bst(NoArvore* raiz, int id) {
    if (raiz == NULL || raiz->produto.id == id) return raiz;
    if (id < raiz->produto.id) return buscar_bst(raiz->esquerda, id);
    return buscar_bst(raiz->direita, id);
}

/* Exibe a arvore ordenada de forma crescente pelo ID */
void exibir_in_order(NoArvore* raiz) {
    if (raiz != NULL) {
        exibir_in_order(raiz->esquerda);
        printf("| ID: %-5d | %-28s | R$ %8.2f | Qtd: %-4d |\n", 
               raiz->produto.id, raiz->produto.nome, raiz->produto.preco, raiz->quantidadeEmEstoque);
        exibir_in_order(raiz->direita);
    }
}

/* Funcao auxiliar para a exclusao: acha o menor no da subarvore direita */
NoArvore* encontrar_minimo(NoArvore* raiz) {
    NoArvore* atual = raiz;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

/* * [Logica de Exclusao na Arvore]: Trata os 3 cenarios classicos:
 * 1. No folha (sem filhos)
 * 2. No com apenas 1 filho (puxa o filho pra cima)
 * 3. No com 2 filhos (substitui pelo sucessor In-Order e deleta o sucessor)
 */
NoArvore* remover_bst(NoArvore* raiz, int id) {
    if (raiz == NULL) return raiz;

    if (id < raiz->produto.id) {
        raiz->esquerda = remover_bst(raiz->esquerda, id);
    } else if (id > raiz->produto.id) {
        raiz->direita = remover_bst(raiz->direita, id);
    } else {
        if (raiz->esquerda == NULL) {
            NoArvore* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            NoArvore* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        NoArvore* temp = encontrar_minimo(raiz->direita);
        raiz->produto = temp->produto;
        raiz->quantidadeEmEstoque = temp->quantidadeEmEstoque;
        raiz->direita = remover_bst(raiz->direita, temp->produto.id);
    }
    return raiz;
}