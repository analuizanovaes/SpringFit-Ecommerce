#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// --- DECLARAÇÃO DE PROTÓTIPOS DE FUNÇÕES ---
void menuListaDupla();    // Catálogo
void menuListaSimples();  // Carrinho
void menuListaCircular(); // Promoções
void menuPilha();         // Histórico
void menuFila();          // Expedição
void menuArvore();        // Estoque/Busca

int main() {
    setlocale(LC_ALL, "");
    int opcao = -1;

    do {
        system("cls || clear");
        printf("+------------------------------------------------+\n");
        printf("|          SPRINGFIT - E-COMMERCE FITNESS        |\n");
        printf("+------------------------------------------------+\n");
        printf("| 1. Catalogo de Produtos (Lista Dupla)          |\n");
        printf("| 2. Carrinho de Compras (Lista Simples)         |\n");
        printf("| 3. Vitrine de Ofertas (Lista Circular)         |\n");
        printf("| 4. Controle de Acoes / Desfazer (Pilha)        |\n");
        printf("| 5. Fila de Pedidos para Expedicao (Fila)       |\n");
        printf("| 6. Gestao de Estoque / Busca (Arvore Binaria)  |\n");
        printf("| 0. Sair do Sistema                             |\n");
        printf("+------------------------------------------------+\n");
        printf("  Escolha o modulo desejado: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\n  [!] Erro: Entrada invalida. Insira um numero.\n");
            while (getchar() != '\n'); 
            system("pause || read -p '  Pressione Enter para continuar...' var");
            continue;
        }

        switch (opcao) {
            case 1: menuListaDupla(); break;
            case 2: menuListaSimples(); break;
            case 3: menuListaCircular(); break;
            case 4: menuPilha(); break;
            case 5: menuFila(); break;
            case 6: menuArvore(); break;
            case 0:
                printf("\n  Encerrando a execucao do sistema SpringFit...\n");
                break;
            default:
                printf("\n  [!] Opcao fora do escopo. Tente novamente.\n");
                system("pause || read -p '  Pressione Enter para continuar...' var");
                break;
        }
    } while (opcao != 0);

    return 0;
}

// --- IMPLEMENTAÇÃO DAS ROTINAS DE INTERFACE (SUBMENUS) ---

void menuListaDupla() {
    int op = -1;
    do {
        system("cls || clear");
        printf("+------------------------------------------------+\n");
        printf("|           CATALOGO DE PRODUTOS (LDE)           |\n");
        printf("+------------------------------------------------+\n");
        printf("| 1. Inserir Produto no Catalogo                 |\n");
        printf("| 2. Remover Produto do Catalogo                 |\n");
        printf("| 3. Percorrer Catalogo (Avanco e Retrocesso)    |\n");
        printf("| 0. Retornar ao Menu Principal                  |\n");
        printf("+------------------------------------------------+\n");
        printf("  Selecione a operacao: ");
        
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
    } while (op != 0);
}

void menuListaSimples() {
    int op = -1;
    do {
        system("cls || clear");
        printf("+------------------------------------------------+\n");
        printf("|           CARRINHO DE COMPRAS (LSE)            |\n");
        printf("+------------------------------------------------+\n");
        printf("| 1. Enfileirar Item no Carrinho                 |\n");
        printf("| 2. Desenfileirar Item do Carrinho              |\n");
        printf("| 3. Percorrer Itens do Carrinho                 |\n");
        printf("| 0. Retornar ao Menu Principal                  |\n");
        printf("+------------------------------------------------+\n");
        printf("  Selecione a operacao: ");
        
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
    } while (op != 0);
}

void menuListaCircular() {
    int op = -1;
    do {
        system("cls || clear");
        printf("+------------------------------------------------+\n");
        printf("|         VITRINE ROTATIVA (L. CIRCULAR)         |\n");
        printf("+------------------------------------------------+\n");
        printf("| 1. Alocar Novo Destaque                        |\n");
        printf("| 2. Iterar Destaques (Simulacao de Loop)        |\n");
        printf("| 0. Retornar ao Menu Principal                  |\n");
        printf("+------------------------------------------------+\n");
        printf("  Selecione a operacao: ");
        
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
    } while (op != 0);
}

void menuPilha() {
    int op = -1;
    do {
        system("cls || clear");
        printf("+------------------------------------------------+\n");
        printf("|           CONTROLE DE ACOES (STACK)            |\n");
        printf("+------------------------------------------------+\n");
        printf("| 1. Empilhar Acao (Push)                        |\n");
        printf("| 2. Desempilhar Ultima Acao (Pop)               |\n");
        printf("| 3. Inspecionar Topo do Historico               |\n");
        printf("| 0. Retornar ao Menu Principal                  |\n");
        printf("+------------------------------------------------+\n");
        printf("  Selecione a operacao: ");
        
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
    } while (op != 0);
}

void menuFila() {
    int op = -1;
    do {
        system("cls || clear");
        printf("+------------------------------------------------+\n");
        printf("|         EXPEDICAO DE PEDIDOS (QUEUE)           |\n");
        printf("+------------------------------------------------+\n");
        printf("| 1. Inserir Pedido na Fila (Enqueue)            |\n");
        printf("| 2. Despachar Primeiro Pedido (Dequeue)         |\n");
        printf("| 3. Monitorar Fila de Espera                    |\n");
        printf("| 0. Retornar ao Menu Principal                  |\n");
        printf("+------------------------------------------------+\n");
        printf("  Selecione a operacao: ");
        
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
    } while (op != 0);
}

void menuArvore() {
    int op = -1;
    do {
        system("cls || clear");
        printf("+------------------------------------------------+\n");
        printf("|            GESTAO DE ESTOQUE (BST)             |\n");
        printf("+------------------------------------------------+\n");
        printf("| 1. Alocar Produto na Arvore                    |\n");
        printf("| 2. Pesquisa Binaria por ID                     |\n");
        printf("| 3. Travessia Em-Ordem (In-Order Traversal)     |\n");
        printf("| 0. Retornar ao Menu Principal                  |\n");
        printf("+------------------------------------------------+\n");
        printf("  Selecione a operacao: ");
        
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
    } while (op != 0);
}
