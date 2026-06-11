#ifndef CATALOGO_H
#define CATALOGO_H
#include "estruturas.h"

void inserir_catalogo(NoDuplo** cabeca, Produto p);
void exibir_catalogo(NoDuplo* cabeca);
NoDuplo* buscar_catalogo(NoDuplo* cabeca, int id);
void remover_catalogo(NoDuplo** cabeca, int id);

#endif