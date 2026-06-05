#include <stdio.h>
#include <stdlib.h>
#include "fila_pedidos.h"

// Inicializa a fila apontando o inicio e o fim para NULL
void inicializarFila(FilaExpedicao *f) {
    f->inicioFila = NULL;
    f->fimFila = NULL;
}

// Verifica se a fila esta vazia
int filaVazia(FilaExpedicao *f) {
    return (f->inicioFila == NULL);
}

// 1. OPERACAO: Inserir no final (Enqueue)
void enqueue(FilaExpedicao *f) {
    Pedido *novo = (Pedido*) malloc(sizeof(Pedido));

    if (novo == NULL) {
        printf("\nErro ao alocar memoria!\n");
        return;
    }

    printf("\nDigite o ID do pedido: ");
    scanf("%d", &novo->id);

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", novo->cliente);

    novo->prox = NULL;

    // Se a fila estiver vazia, o novo no e o inicio e o fim
    if (filaVazia(f)) {
        f->inicioFila = novo;
        f->fimFila = novo;
    } else {
        // Caso contrario, liga o ultimo no ao novo e atualiza o fim
        f->fimFila->prox = novo;
        f->fimFila = novo;
    }

    printf("\nPedido inserido com sucesso!\n");
}

// 2. OPERACAO: Remover do inicio (Dequeue - FIFO)
void dequeue(FilaExpedicao *f) {
    if (filaVazia(f)) {
        printf("\nFila vazia!\n");
        return;
    }

    Pedido *temp = f->inicioFila;

    printf("\nPedido enviado com sucesso!\n");
    printf("ID: %d\n", temp->id);
    printf("Cliente: %s\n", temp->cliente);

    // O inicio da fila avanca para o proximo elemento
    f->inicioFila = f->inicioFila->prox;

    // Se a fila ficou vazia, o fim tambem aponta para NULL
    if (f->inicioFila == NULL) {
        f->fimFila = NULL;
    }

    free(temp); // Libera a memoria do no removido
}

// 3. OPERACAO: Buscar pedido por ID
void buscarPedido(FilaExpedicao *f) {
    if (filaVazia(f)) {
        printf("\nFila vazia!\n");
        return;
    }

    int idBusca;
    int encontrado = 0;

    printf("\nDigite o ID do pedido para busca: ");
    scanf("%d", &idBusca);

    Pedido *aux = f->inicioFila;

    // Percorre toda a fila buscando o ID desejado
    while (aux != NULL) {
        if (aux->id == idBusca) {
            printf("\nPedido encontrado!\n");
            printf("ID: %d\n", aux->id);
            printf("Cliente: %s\n", aux->cliente);
            encontrado = 1;
            break;
        }
        aux = aux->prox;
    }

    if (!encontrado) {
        printf("\nPedido nao encontrado!\n");
    }
}

// 4. OPERACAO: Exibir fila atual
void exibirFila(FilaExpedicao *f) {
    if (filaVazia(f)) {
        printf("\nFila vazia!\n");
        return;
    }

    Pedido *aux = f->inicioFila;

    printf("\n========== FILA DE PEDIDOS ==========\n");
    while (aux != NULL) {
        printf("ID: %d | Cliente: %s\n", aux->id, aux->cliente);
        aux = aux->prox;
    }
    printf("=====================================\n");
}
