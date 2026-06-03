#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// --- ENTIDADES BASE DO SISTEMA ---

// Estrutura de dados para representação dos atributos de um Produto.
typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

// Estrutura de dados para consolidação e faturamento de um Pedido.
typedef struct {
    int idPedido;
    float valorTotal;
} Pedido;

// --- DEFINIÇÃO DOS NÓS (NODES) DAS ESTRUTURAS DE DADOS ---

// Nó para Lista Simplesmente Encadeada (LSE) e Pilha (Stack).
// Mantém um ponteiro de encadeamento unidirecional para o próximo nó.
typedef struct NoSimples {
    Produto produto;
    struct NoSimples* proximo;
} NoSimples;

// Nó para Lista Duplamente Encadeada (LDE) e Lista Circular.
// Possui ponteiros bidirecionais para permitir a travessia e manipulação em ambos os sentidos.
typedef struct NoDuplo {
    Produto produto;
    struct NoDuplo* anterior;
    struct NoDuplo* proximo;
} NoDuplo;

// Nó para Fila (Queue) com política FIFO (First-In, First-Out).
// Encapsula o Pedido e mantém a referência para o próximo nó da fila de expedição.
typedef struct NoFila {
    Pedido pedido;
    struct NoFila* proximo;
} NoFila;

// Nó para Árvore Binária de Busca (BST - Binary Search Tree).
// Armazena a quantidade em estoque e mantém ramificações para subárvore esquerda e direita.
typedef struct NoArvore {
    Produto produto;
    int quantidadeEmEstoque;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

#endif
