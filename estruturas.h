#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// --- DADOS BASE DA LOJA ---

// Ficha com os dados básicos de cada peça de roupa ou acessório
typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

// Ficha para guardar o resumo de um pedido finalizado pelo cliente
typedef struct {
    int idPedido;
    float valorTotal;
} Pedido;

// --- NÓS (As caixinhas que vão segurar nossos dados na memória) ---

// Usado no Carrinho (Lista Simples) e no Histórico (Pilha)
// Como é simples, a gente só precisa de um ponteiro para ir pro próximo item
typedef struct NoSimples {
    Produto produto;
    struct NoSimples* proximo;
} NoSimples;

// Usado no Catálogo (Lista Dupla) e nas Promoções (Lista Circular)
// Tem ponteiro pra ir e pra voltar (por isso é duplo), facilita a navegação
typedef struct NoDuplo {
    Produto produto;
    struct NoDuplo* anterior;
    struct NoDuplo* proximo;
} NoDuplo;

// Usado na Expedição (Fila)
// Guarda o pedido fechado e aponta para o próximo pedido que está na fila de espera
typedef struct NoFila {
    Pedido pedido;
    struct NoFila* proximo;
} NoFila;

// Usado no Controle de Estoque (Árvore Binária)
// Além do produto e da quantidade, tem dois caminhos (esquerda/direita) para organizar as buscas rápido
typedef struct NoArvore {
    Produto produto;
    int quantidadeEmEstoque;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

#endif
