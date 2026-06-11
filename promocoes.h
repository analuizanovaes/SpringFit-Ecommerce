#ifndef PROMOCOES_H
#define PROMOCOES_H
#include "estruturas.h"

void inserir_promocao(NoDuplo** cabeca, Produto p);
void exibir_carrossel(NoDuplo* cabeca, int giros);
void remover_promocao(NoDuplo** cabeca, int id);

#endif