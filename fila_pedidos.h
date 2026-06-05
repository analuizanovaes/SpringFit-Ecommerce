#ifndef FILA_PEDIDOS_H
#define FILA_PEDIDOS_H

// Estrutura do No da fila representando o Pedido
typedef struct Pedido {
    int id;
    char cliente[50];
    struct Pedido *prox;
} Pedido;

// Estrutura de controle para o inicio e o fim da fila
typedef struct {
    Pedido *inicioFila;
    Pedido *fimFila;
} FilaExpedicao;

// Prototipos das operacoes do checklist
void inicializarFila(FilaExpedicao *f);
int filaVazia(FilaExpedicao *f);
void enqueue(FilaExpedicao *f);      // Inserir no final
void dequeue(FilaExpedicao *f);      // Remover do inicio
void buscarPedido(FilaExpedicao *f);   // Buscar pedido
void exibirFila(FilaExpedicao *f);     // Exibir fila atual

#endif
