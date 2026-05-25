#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// --- DECLARAÇÃO DE PROTÓTIPOS DE FUNÇÕES ---
// (Os menus específicos serão implementados nos seus respectivos módulos/arquivos)
void menuListaSimples();
void menuListaDupla();
void menuListaCircular();
void menuPilha();
void menuFila();
void menuArvore();

int main() {
    // Configura a acentuação para o português
    setlocale(LC_ALL, "Portuguese");
    
    int opcao = -1;

    // Loop principal do sistema SpringFit
    do {
        system("cls || clear"); // Limpa a tela de forma multiplataforma
        printf("==================================================\n");
        printf("          SPRINGFIT - E-COMMERCE FITNESS          \n");
        printf("==================================================\n");
        printf("1. Catálogo de Produtos (Lista Simplesmente Encadeada)\n");
        printf("2. Carrinho de Compras (Lista Duplamente Encadeada)\n");
        printf("3. Vitrine de Ofertas (Lista Circular)\n");
        printf("4. Histórico de Navegação / Desfazer Ação (Pilha)\n");
        printf("5. Fila de Pedidos para Expedição (Fila)\n");
        printf("6. Busca Rápida / Categorias (Árvore Binária)\n");
        printf("0. Sair do Sistema\n");
        printf("==================================================\n");
        printf("Escolha uma opção: ");
        
        // Tratamento básico de erro na leitura da opção
        if (scanf("%d", &opcao) != 1) {
            printf("\nErro: Entrada inválida! Digite um número.\n");
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
                printf("\nEncerrando o sistema SpringFit. Até logo!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                system("pause || read -p 'Pressione Enter para continuar...' var");
                break;
        }

    } while (opcao != 0);

    return 0;
}

// --- IMPLEMENTAÇÃO DOS SUBMENUS (ESQUELETOS) ---

void menuListaSimples() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Catálogo de Produtos ---\n");
        printf("1. Cadastrar Roupa\n");
        printf("2. Remover do Catálogo\n");
        printf("3. Exibir Catálogo Completo\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        
        // Aqui entrará a lógica das operações fundamentais da estrutura
    } while (op != 0);
}

void menuListaDupla() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Carrinho de Compras ---\n");
        printf("1. Adicionar Item ao Carrinho\n");
        printf("2. Remover Item do Carrinho\n");
        printf("3. Visualizar Carrinho (Avançar e Voltar)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
    } while (op != 0);
}

void menuListaCircular() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Vitrine de Ofertas Rotativas ---\n");
        printf("1. Adicionar Destaque\n");
        printf("2. Mostrar Próxima Oferta (Loop)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
    } while (op != 0);
}

void menuPilha() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Histórico de Ações (Desfazer) ---\n");
        printf("1. Registrar Nova Ação (Push)\n");
        printf("2. Desfazer Última Ação (Pop)\n");
        printf("3. Mostrar Histórico Recente\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
    } while (op != 0);
}

void menuFila() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Fila de Envio de Pedidos ---\n");
        printf("1. Novo Pedido Concluído (Enqueue)\n");
        printf("2. Enviar Próximo Pedido da Fila (Dequeue)\n");
        printf("3. Mostrar Fila de Espera\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
    } while (op != 0);
}

void menuArvore() {
    int op = -1;
    do {
        system("cls || clear");
        printf("--- Busca por ID / Categoria ---\n");
        printf("1. Inserir Produto na Árvore de Busca\n");
        printf("2. Buscar Produto por Código (ID)\n");
        printf("3. Exibir Árvore Em-Ordem (Ordenado por ID)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
    } while (op != 0);
}
