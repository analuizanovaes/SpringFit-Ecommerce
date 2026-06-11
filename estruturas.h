/* =================================================================================================================================================================================
 * Centro Universitario UniEuro - Analise e Desenvolvimento de Sistemas (ADS)
 * Disciplina: Estrutura de Dados | Prof: Jorge Osvaldo Alves de Lima Torres
 * Desenvolvedoras: Ana Luiza Fernandes Novaes e Sthefanny Ramos Parrini
 * Centralizamos as structs neste arquivo para evitar redefinicoes multiplas de memoria. Criamos nos especificos para cada necessidade de ponteiro (Simples, Duplo, Arvore e Fila).
====================================================================================================================================================================================
*/

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

/* Entidade principal do banco de dados ficticio */
typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

/* Entidade de faturamento para uso exclusivo da logistica */
typedef struct {
    int idPedido;
    float valorTotal;
} Pedido;

/* No Simples: Ocupa menos memoria RAM. Usado no Carrinho e na Pilha. */
typedef struct NoSimples {
    Produto produto;
    int quantidade; 
    struct NoSimples* proximo;
} NoSimples;

/* No Duplo: Possui navegacao bidirecional. Usado no Catalogo e Promocoes. */
typedef struct NoDuplo {
    Produto produto;
    struct NoDuplo* anterior;
    struct NoDuplo* proximo;
} NoDuplo;

/* No Fila: Encapsula a entidade Pedido isolando-a do fluxo de Produtos. */
typedef struct NoFila {
    Pedido pedido;
    struct NoFila* proximo;
} NoFila;

/* No Arvore: Ramificacao binaria para busca otimizada O(log n). */
typedef struct NoArvore {
    Produto produto;
    int quantidadeEmEstoque;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

#endif