#include <stdio.h>
#include <stdlib.h>
#include "desfazer.h"

// Inicializa o topo da pilha como NULL
void inicializarPilha(PilhaDesfazer *p) {
    p->topo = NULL;
}

// Verifica se a pilha esta vazia
int pilhaVazia(PilhaDesfazer *p) {
    return (p->topo == NULL);
}

// 1. OPERACAO: Empilhar acao (Push)
void pushAcao(PilhaDesfazer *p) {
    Acao *novo = (Acao*) malloc(sizeof(Acao));

    if (novo == NULL) {
        printf("\nErro ao alocar memoria para o historico!\n");
        return;
    }

    printf("\nDigite o ID do produto da acao atual: ");
    scanf("%d", &novo->idProduto);

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novo->nomeProduto);

    // O proximo do novo no aponta para o antigo topo
    novo->prox = p->topo;
    
    // O topo passa a ser o novo no inserido
    p->topo = novo;

    printf("\nAcao registrada no historico com sucesso!\n");
}

// 2. OPERACAO: Desempilhar acao (Pop - Desfazer)
void popAcao(PilhaDesfazer *p) {
    if (pilhaVazia(p)) {
        printf("\nNao ha acoes para desfazer!\n");
        return;
    }

    Acao *temp = p->topo;

    printf("\nDesfazendo ultima acao com sucesso!\n");
    printf("ID Produto Removido: %d\n", temp->idProduto);
    printf("Produto Removido: %s\n", temp->nomeProduto);

    // O topo aponta para o elemento de baixo
    p->topo = p->topo->prox;

    free(temp); // Libera a memoria da acao revertida
}

// 3. OPERACAO: Buscar no historico da pilha
void buscarHistorico(PilhaDesfazer *p) {
    if (pilhaVazia(p)) {
        printf("\nHistorico vazio!\n");
        return;
    }

    int idBusca;
    int encontrado = 0;
    int posicao = 1;

    printf("\nDigite o ID do produto para buscar no historico: ");
    scanf("%d", &idBusca);

    Acao *aux = p->topo;

    // Varre a pilha a partir do topo procurando o registro
    while (aux != NULL) {
        if (aux->idProduto == idBusca) {
            printf("\nAcao encontrada no historico!\n");
            printf("ID: %d | Produto: %s\n", aux->idProduto, aux->nomeProduto);
            printf("Posicao na pilha (de cima para baixo): %d\n", posicao);
            encontrado = 1;
            break;
        }
        aux = aux->prox;
        posicao++;
    }

    if (!encontrado) {
        printf("\nNenhum registro encontrado para o ID %d.\n", idBusca);
    }
}

// 4. OPERACAO: Exibir apenas o topo da pilha
void exibirTopo(PilhaDesfazer *p) {
    if (pilhaVazia(p)) {
        printf("\nNenhuma acao no topo. Pilha vazia!\n");
        return;
    }

    printf("\n--- PROXIMA ACAO A SER DESFEITA (TOPO) ---\n");
    printf("ID Produto: %d\n", p->topo->idProduto);
    printf("Produto: %s\n", p->topo->nomeProduto);
    printf("==========================================\n");
}
