#include <stdio.h>
#include <stdlib.h>
#include "carrinho.h"

// Inicializa o carrinho com o ponteiro de inicio apontando para NULL
void inicializarCarrinho(CarrinhoCompras *c) {
    c->inicio = NULL;
}

// Verifica se o carrinho esta vazio
int carrinhoVazio(CarrinhoCompras *c) {
    return (c->inicio == NULL);
}

// 1. OPERACAO: Inserir item (Insercao no inicio da lista para simplificar)
void inserirItem(CarrinhoCompras *c) {
    ItemCarrinho *novo = (ItemCarrinho*) malloc(sizeof(ItemCarrinho));

    if (novo == NULL) {
        printf("\nErro ao alocar memoria para o item!\n");
        return;
    }

    printf("\nDigite o ID do produto: ");
    scanf("%d", &novo->idProduto);

    printf("Digite o nome do produto fitness: ");
    scanf(" %[^\n]", novo->nomeProduto);

    printf("Digite a quantidade: ");
    scanf("%d", &novo->quantidade);

    printf("Digite o preco unitario: ");
    scanf("%f", &novo->preco);

    // O novo no aponta para o antigo primeiro no da lista
    novo->prox = c->inicio;
    
    // O inicio da lista passa a ser o novo no
    c->inicio = novo;

    printf("\nItem adicionado ao carrinho com sucesso!\n");
}

// 2. OPERACAO: Remover item por ID (Remocao em qualquer posicao da lista)
void removerItem(CarrinhoCompras *c) {
    if (carrinhoVazio(c)) {
        printf("\nO carrinho ja esta vazio!\n");
        return;
    }

    int idBusca;
    printf("\nDigite o ID do produto que deseja remover do carrinho: ");
    scanf("%d", &idBusca);

    ItemCarrinho *atual = c->inicio;
    ItemCarrinho *anterior = NULL;

    // Busca o elemento na lista guardando a referencia do nó anterior
    while (atual != NULL && atual->idProduto != idBusca) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se nao encontrou o produto
    if (atual == NULL) {
        printf("\nProduto com ID %d nao foi encontrado no carrinho!\n", idBusca);
        return;
    }

    // Se o elemento a ser removido for o primeiro da lista
    if (anterior == NULL) {
        c->inicio = atual->prox;
    } else {
        // Se estiver no meio ou fim, o anterior pula o atual e aponta para o proximo
        anterior->prox = atual->prox;
    }

    printf("\nItem removido: %s (Quantidade: %d) removido do carrinho!\n", atual->nomeProduto, atual->quantidade);
    free(atual); // Libera a memoria
}

// 3. OPERACAO: Buscar item por ID
void buscarItem(CarrinhoCompras *c) {
    if (carrinhoVazio(c)) {
        printf("\nCarrinho vazio! Nao ha o que buscar.\n");
        return;
    }

    int idBusca;
    int encontrado = 0;
    printf("\nDigite o ID do produto para buscar no carrinho: ");
    scanf("%d", &idBusca);

    ItemCarrinho *aux = c->inicio;

    while (aux != NULL) {
        if (aux->idProduto == idBusca) {
            printf("\n--- ITEM ENCONTRADO NO CARRINHO ---\n");
            printf("ID: %d\n", aux->idProduto);
            printf("Produto: %s\n", aux->nomeProduto);
            printf("Quantidade: %d\n", aux->quantidade);
            printf("Preco Unitario: R$ %.2f\n", aux->preco);
            printf("Subtotal: R$ %.2f\n", aux->preco * aux->quantidade);
            encontrado = 1;
            break;
        }
        aux = aux->prox;
    }

    if (!encontrado) {
        printf("\nProduto com ID %d nao esta no seu carrinho.\n", idBusca);
    }
}

// 4. OPERACAO: Exibir carrinho
void exibirCarrinho(CarrinhoCompras *c) {
    if (carrinhoVazio(c)) {
        printf("\nSeu carrinho de compras esta vazio!\n");
        return;
    }

    ItemCarrinho *aux = c->inicio;
    float totalGeral = 0.0;

    printf("\n========== CARRINHO DE COMPRAS (SPRINGFIT) ==========\n");
    while (aux != NULL) {
        float subtotal = aux->preco * aux->quantidade;
        printf("ID: %d | %-20s | Qtd: %d | Preco: R$ %.2f | Subtotal: R$ %.2f\n", 
               aux->idProduto, aux->nomeProduto, aux->quantidade, aux->preco, subtotal);
        totalGeral += subtotal;
        aux = aux->prox;
    }
    printf("-----------------------------------------------------\n");
    printf("TOTAL GERAL DO CARRINHO: R$ %.2f\n", totalGeral);
    printf("=====================================================\n");
}
