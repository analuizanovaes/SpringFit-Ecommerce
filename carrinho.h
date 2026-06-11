#ifndef CARRINHO_H
#define CARRINHO_H
#include "estruturas.h"

void adicionar_carrinho(NoSimples** cabeca, Produto p, int qtd);
void remover_do_carrinho(NoSimples** cabeca, int id_produto);
float exibir_carrinho_e_calcular_total(NoSimples* cabeca);
void limpar_carrinho(NoSimples** cabeca);

#endif