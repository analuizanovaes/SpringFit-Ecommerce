#ifndef CARRINHO_H
#define CARRINHO_H

// Estrutura do No da Lista Simplesmente Encadeada representando um Item do Carrinho
typedef struct ItemCarrinho {
    int idProduto;
    char nomeProduto[50];
    int quantidade;
    float preco;
    struct ItemCarrinho *prox;
} ItemCarrinho;

// Estrutura de controle para a cabeça (inicio) da lista
typedef struct {
    ItemCarrinho *inicio;
} CarrinhoCompras;

// Prototipos das operacoes do checklist
void inicializarCarrinho(CarrinhoCompras *c);
int carrinhoVazio(CarrinhoCompras *c);
void inserirItem(CarrinhoCompras *c);  // Inserir item
void removerItem(CarrinhoCompras *c);  // Remover item
void buscarItem(CarrinhoCompras *c);   // Buscar item
void exibirCarrinho(CarrinhoCompras *c); // Exibir carrinho

#endif
