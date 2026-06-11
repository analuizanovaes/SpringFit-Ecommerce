#ifndef PILHA_HISTORICO_H
#define PILHA_HISTORICO_H
#include "estruturas.h"

void push_historico(NoSimples** topo, Produto p, int qtd);
NoSimples pop_historico(NoSimples** topo);

#endif