#ifndef FILA_PEDIDOS_H
#define FILA_PEDIDOS_H
#include "estruturas.h"

typedef struct {
    NoFila* inicio;
    NoFila* fim;
} FilaExpedicao;

void inicializar_fila(FilaExpedicao* f);
void enfileirar_pedido(FilaExpedicao* f, Pedido ped);
void desenfileirar_pedido(FilaExpedicao* f);

#endif