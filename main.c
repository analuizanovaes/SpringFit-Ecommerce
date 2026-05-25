#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// --- DECLARACAO DE PROTOTIPOS DE FUNCOES ---
// (Os menus especificos serao implementados nos seus respectivos modulos/arquivos)
void menuListaSimples();
void menuListaDupla();
void menuListaCircular();
void menuPilha();
void menuFila();
void menuArvore();

int main() {
    // Configura a linguagem
    setlocale(LC_ALL, "");
    
    int opcao = -1;

    // Loop principal do sistema SpringFit
    do {
        system("cls || clear"); // Limpa a tela de forma multiplataforma
        printf("==================================================\n");
        printf("          SPRINGFIT - E-COMMERCE FITNESS          \n");
        printf("==================================================\n");
        printf("1. Catalogo de Produtos (Lista Simplesmente Encadeada)\n");
        printf("2. Carrinho de Compras (Lista Duplamente Encadeada)\n");
        printf("3. Vitrine de Ofertas (Lista Circular)\n");
        printf("4. Historico de Navegacao / Desfazer Acao (Pilha)\n");
        printf("5. Fila de Pedidos para Expedicao (Fila)\n");
        printf("6. Busca Rapida / Categorias (Arvore Binaria)\n");
        printf("0. Sair do Sistema\n");
        printf("==================================================\n");
        printf("Escolha uma opcao: ");
        
        // Tratamento basico de erro na leitura da opcao
        if (scanf("%d", &opcao) != 1) {
            printf("\nErro: Entrada invalida! Digite um numero.\n");
            while (getchar() != '\n'); // Limpa o buffer do teclado
            system("pause || read -p 'Pressione Enter para continuar...' var");
            continue;
        }

        switch (opcao) {
            case 1:
                menuListaSimples();
                break;
            case 2:
                menuListaDupla();
                break;
            case 3:
                menuListaCircular();
                break;
            case 4:
                menuPilha();
                break;
            case 5:
                menuFila();
                break;
            case 6:
                menuArvore();
                break;
            case 0:
                printf("\nEncerrando o sistema SpringFit. Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                system("pause || read -p 'Pressione Enter para continuar...' var");
                break;
        }

    } while (opcao != 0);

    return 0;
}

// --- IMPLEMENTACAO DOS SUBMENUS (ESQUELETOS) ---

void menuListaSimples() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Catalogo de Produtos ---\n");
        printf("1. Cadastrar Roupa\n");
        printf("2. Remover do Catalogo\n");
        printf("3. Exibir Catalogo Completo\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        
        // Aqui entrara a logica das operacoes fundamentais da estrutura
    } while (op != 0);
}

void menuListaDupla() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Carrinho de Compras ---\n");
        printf("1. Adicionar Item ao Carrinho\n");
        printf("2. Remover Item do Carrinho\n");
        printf("3. Visualizar Carrinho (Avancar e Voltar)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
    } while (op != 0);
}

void menuListaCircular() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Vitrine de Ofertas Rotativas ---\n");
        printf("1. Adicionar Destaque\n");
        printf("2. Mostrar Proxima Oferta (Loop)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
    } while (op != 0);
}

void menuPilha() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Historico de Acoes (Desfazer) ---\n");
        printf("1. Registrar Nova Acao (Push)\n");
        printf("2. Desfazer Ultima Acao (Pop)\n");
        printf("3. Mostrar Historico Recente\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
    } while (op != 0);
}

void menuFila() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Fila de Envio de Pedidos ---\n");
        printf("1. Novo Pedido Concluido (Enqueue)\n");
        printf("2. Enviar Proximo Pedido da Fila (Dequeue)\n");
        printf("3. Mostrar Fila de Espera\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
    } while (op != 0);
}

void menuArvore() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Busca por ID / Categoria ---\n");
        printf("1. Inserir Produto na Arvore de Busca\n");
        printf("2. Buscar Produto por Codigo (ID)\n");
        printf("3. Exibir Arvore Em-Ordem (Ordenado por ID)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
    } while (op != 0);
}
