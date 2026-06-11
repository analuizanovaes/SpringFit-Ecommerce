#ifndef ESTOQUE_BST_H
#define ESTOQUE_BST_H
#include "estruturas.h"

NoArvore* inserir_bst(NoArvore* raiz, Produto p, int qtd);
NoArvore* buscar_bst(NoArvore* raiz, int id);
void exibir_in_order(NoArvore* raiz);
NoArvore* encontrar_minimo(NoArvore* raiz);
NoArvore* remover_bst(NoArvore* raiz, int id);

#endif