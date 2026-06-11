/* 
==================================================================================================================================================================================
 * Estrutura: Lista Simplesmente Encadeada
 * Para o carrinho temporario, optamos pela Lista Simples. Ela gasta muito menos memoria RAM do que a Lista Dupla, sendo a decisao de engenharia ideal para juntar produtos antes do checkout.
====================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "carrinho.h"

/* Insercao no inicio (Head) garante complexidade super rapida de O(1) */
void adicionar_carrinho(NoSimples** cabeca, Produto p, int qtd) {
    NoSimples* novo = (NoSimples*)malloc(sizeof(NoSimples));
    if (novo == NULL) return;
    
    novo->produto = p;
    novo->quantidade = qtd;
    novo->proximo = *cabeca;
    *cabeca = novo;
}

/* Travessia linear com ponteiro auxiliar para manter o fio da lista */
void remover_do_carrinho(NoSimples** cabeca, int id_produto) {
    NoSimples* temp = *cabeca;
    NoSimples* anteriorNo = NULL;

    if (temp != NULL && temp->produto.id == id_produto) {
        *cabeca = temp->proximo;
        free(temp); 
        return;
    }
    
    while (temp != NULL && temp->produto.id != id_produto) {
        anteriorNo = temp;
        temp = temp->proximo;
    }
    
    if (temp == NULL) return;
    
    anteriorNo->proximo = temp->proximo;
    free(temp); 
}

/* Exibe a lista e calcula os subtotais on the fly */
float exibir_carrinho_e_calcular_total(NoSimples* cabeca) {
    NoSimples* temp = cabeca;
    float total = 0.0;
    
    if (temp == NULL) {
        printf("| Seu carrinho de compras esta vazio.                                |\n");
        return total;
    }
    
    while (temp != NULL) {
        float subtotal = temp->produto.preco * temp->quantidade;
        printf("| * %-2dx %-28s | R$ %8.2f | Sub: %7.2f    |\n", 
               temp->quantidade, temp->produto.nome, temp->produto.preco, subtotal);
        total += subtotal;
        temp = temp->proximo;
    }
    return total;
}

/* [Logica de Seguranca]: Varre o carrinho apos a compra aplicando free() para evitar vazamento de memoria no servidor. */
void limpar_carrinho(NoSimples** cabeca) {
    NoSimples* temp = *cabeca;
    NoSimples* proxNo;
    
    while (temp != NULL) {
        proxNo = temp->proximo;
        free(temp);
        temp = proxNo;
    }
    *cabeca = NULL;
}