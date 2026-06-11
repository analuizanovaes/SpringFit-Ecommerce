/* 
===========================================================================================================================================================================
 * Estrutura: Pilha (Stack) - Politica LIFO
 * A Pilha e a estrutura nativa por tras do 'Ctrl+Z'. Usamos a politica Last In, First Out para garantir que o cliente remova estritamente a ultima acao realizada caso se arrependa da insercao no carrinho."
============================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha_historico.h"

/* Operacao PUSH: Insere no Topo */
void push_historico(NoSimples** topo, Produto p, int qtd) {
    NoSimples* novo = (NoSimples*)malloc(sizeof(NoSimples));
    if (novo == NULL) return;
    
    novo->produto = p;
    novo->quantidade = qtd;
    novo->proximo = *topo;
    *topo = novo; 
}

/* Operacao POP: Remove do Topo e devolve os dados resgatados */
NoSimples pop_historico(NoSimples** topo) {
    NoSimples item_vazio;
    item_vazio.produto.id = 0;
    item_vazio.quantidade = 0;
    item_vazio.proximo = NULL;

    if (*topo == NULL) return item_vazio; // Pilha vazia

    NoSimples* temp = *topo;
    NoSimples item_removido;
    
    item_removido.produto = temp->produto;
    item_removido.quantidade = temp->quantidade;
    item_removido.proximo = NULL;
    
    *topo = temp->proximo;
    free(temp); // Seguranca de memoria
    
    return item_removido;
}