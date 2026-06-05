#ifndef DESFAZER_H
#define DESFAZER_H

// Estrutura do No da Pilha representando uma Acao do usuario
typedef struct Acao {
    int idProduto;
    char nomeProduto[50];
    struct Acao *prox;
} Acao;

// Estrutura de controle para o topo da pilha
typedef struct {
    Acao *topo;
} PilhaDesfazer;

// Prototipos das operacoes do checklist
void inicializarPilha(PilhaDesfazer *p);
int pilhaVazia(PilhaDesfazer *p);
void pushAcao(PilhaDesfazer *p);        // Empilhar acao
void popAcao(PilhaDesfazer *p);         // Desempilhar acao
void buscarHistorico(PilhaDesfazer *p);  // Buscar no historico
void exibirTopo(PilhaDesfazer *p);       // Exibir topo da pilha

#endif
