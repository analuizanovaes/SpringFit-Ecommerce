/* 
====================================================================================================================================================================================
 * Tipo: Orquestrador / Interface
 * Aqui demonstramos a interconexao real. O main e o maestro: ele consome os produtos da Arvore (Back-end) e interage com o Carrinho (Sessao do usuario) ate finalizar e despachar na Fila (Logistica).
 * Compilação: gcc main.c estoque_bst.c catalogo.c carrinho.c pilha_historico.c fila_pedidos.c promocoes.c -o springfit ; ./springfit.exe
====================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

/* Inclusao de todos os modulos construidos manualmente */
#include "estruturas.h"
#include "estoque_bst.h"
#include "catalogo.h"
#include "carrinho.h"
#include "pilha_historico.h"
#include "fila_pedidos.h"
#include "promocoes.h"

int main() {
    /* 1. Alocacao inicial segura (Ponteiros vazios) */
    NoArvore* estoque = NULL;           
    NoDuplo* catalogo = NULL;           
    NoSimples* carrinho = NULL;         
    NoSimples* historico = NULL;        
    FilaExpedicao expedicao;            
    inicializar_fila(&expedicao);
    NoDuplo* carrossel_promocoes = NULL;

    int id_gerador_pedidos = 5001;

    /* 2. Carga Inicial do Banco de Dados Ficticio */
    Produto p1 = {101, "Legging Compressao", 89.90};
    Produto p2 = {102, "Top Fit Academia", 45.50};
    Produto p3 = {103, "Camiseta DryFit", 59.90};
    Produto p4 = {104, "Tenis UltraRunner", 199.99};
    Produto p5 = {105, "Garrafa Termica 2L", 65.00};
    Produto p6 = {106, "Bermuda Moletom", 75.90};
    Produto p7 = {107, "Luva de Musculacao", 35.00};
    Produto p8 = {108, "Whey Protein 900g", 149.90};
    Produto p9 = {109, "Corda de Pular", 25.50};
    Produto p10 = {110, "Mochila Esportiva", 129.90};

    // Populando Arvore BST com insercoes descentralizadas
    estoque = inserir_bst(estoque, p5, 30);
    estoque = inserir_bst(estoque, p2, 12);
    estoque = inserir_bst(estoque, p8, 50);
    estoque = inserir_bst(estoque, p1, 20);
    estoque = inserir_bst(estoque, p3, 25);
    estoque = inserir_bst(estoque, p4, 8);
    estoque = inserir_bst(estoque, p6, 15);
    estoque = inserir_bst(estoque, p7, 40);
    estoque = inserir_bst(estoque, p9, 60);
    estoque = inserir_bst(estoque, p10, 10);

    // Vetor auxiliar de carregamento O(n)
    Produto array_aux[] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10};
    for(int i = 0; i < 10; i++) {
        inserir_catalogo(&catalogo, array_aux[i]);
    }

    inserir_promocao(&carrossel_promocoes, p8);
    inserir_promocao(&carrossel_promocoes, p4);
    inserir_promocao(&carrossel_promocoes, p10);

    int opcao = 0;

    /* 3. Loop Interativo (O Core do Terminal) */
    do {
        // [Formatacao Visual]: Uso padronizado de tamanho dinamico nas strings
        printf("\n+--------------------------------------------------------------------+\n");
        printf("|    SPRINGFIT: SEU E-COMMERCE DE ROUPAS E ACESSORIOS DE ACADEMIA    |\n");
        printf("+--------------------------------------------------------------------+\n");
        printf("| [1] Ver Catalogo (Lista Duplamente Encadeada)                      |\n");
        printf("| [2] Ver Ofertas  (Lista Circular)                                  |\n");
        printf("| [3] Buscar Item  (Arvore Binaria de Busca - BST)                   |\n");
        printf("| [4] Comprar Item (Inserir na Lista Simples)                        |\n");
        printf("| [5] Ver Carrinho (Percorrer Lista Simples)                         |\n");
        printf("| [6] Desfazer     (Remover da Pilha / LIFO)                         |\n");
        printf("|--------------------------------------------------------------------|\n");
        printf("| [7] Finalizar Compra (Enviar para Fila / FIFO)                     |\n");
        printf("| [8] Processar Pedido (Remover da Fila / FIFO)                      |\n");
        printf("|--------------------------------------------------------------------|\n");
        printf("| [0] Sair do Sistema                                                |\n");
        printf("+--------------------------------------------------------------------+\n");
        printf(">> Escolha uma operacao: ");
        
        // Protecao do buffer do teclado (impede loop infinito se digitar letras)
        if (scanf("%d", &opcao) != 1) {
            printf("\n+--------------------------------------------------------------------+\n");
            printf("| [!] Falha: Entrada invalida! Por favor, digite um numero.          |\n");
            printf("+--------------------------------------------------------------------+\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\n+--------------------------------------------------------------------+\n");
                printf("|                          CATALOGO DA LOJA                          |\n");
                printf("+--------------------------------------------------------------------+\n");
                exibir_catalogo(catalogo);
                printf("+--------------------------------------------------------------------+\n");
                break;
                
            case 2:
                printf("\n+--------------------------------------------------------------------+\n");
                printf("|                         OFERTAS ROTATIVAS                          |\n");
                printf("+--------------------------------------------------------------------+\n");
                exibir_carrossel(carrossel_promocoes, 5); 
                printf("+--------------------------------------------------------------------+\n");
                break;
                
            case 3: {
                int idBusca;
                printf("\n>> Digite o ID do produto para buscar na BST: ");
                scanf("%d", &idBusca);
                
                printf("\n+--------------------------------------------------------------------+\n");
                printf("|                         RESULTADO DA BUSCA                         |\n");
                printf("+--------------------------------------------------------------------+\n");
                
                NoArvore* enc = buscar_bst(estoque, idBusca);
                
                if (enc != NULL) {
                    printf("| Encontrado: %-54s |\n", enc->produto.nome);
                    printf("| Preco: R$ %6.2f | Em Estoque: %-3d unid.                           |\n", 
                           enc->produto.preco, enc->quantidadeEmEstoque);
                } else {
                    printf("| [!] Produto com ID %-4d nao localizado na arvore binaria.          |\n", idBusca);
                }
                printf("+--------------------------------------------------------------------+\n");
                break;
            }
            
            case 4: {
                int idAdd, qtdAdd;
                printf("\n>> Digite o ID do produto que deseja colocar no carrinho: ");
                scanf("%d", &idAdd);
                NoArvore* pEstoque = buscar_bst(estoque, idAdd);
                
                if (pEstoque != NULL && pEstoque->quantidadeEmEstoque > 0) {
                    printf(">> Digite a quantidade (Disponivel: %d): ", pEstoque->quantidadeEmEstoque);
                    scanf("%d", &qtdAdd);
                    
                    printf("\n+--------------------------------------------------------------------+\n");
                    if (qtdAdd > 0 && qtdAdd <= pEstoque->quantidadeEmEstoque) {
                        
                        // Atualiza as estruturas integradas
                        adicionar_carrinho(&carrinho, pEstoque->produto, qtdAdd);
                        push_historico(&historico, pEstoque->produto, qtdAdd); 
                        pEstoque->quantidadeEmEstoque -= qtdAdd; 
                        
                        printf("| [+] %2d unid. de %-25s adicionada(s)!           |\n", 
                               qtdAdd, pEstoque->produto.nome);
                    } else {
                        printf("| [!] Quantidade incorreta ou limite de estoque excedido.            |\n");
                    }
                    printf("+--------------------------------------------------------------------+\n");
                } else if (pEstoque != NULL) {
                    printf("\n+--------------------------------------------------------------------+\n");
                    printf("| [!] Erro de logistica: Este produto encontra-se esgotado.          |\n");
                    printf("+--------------------------------------------------------------------+\n");
                } else {
                    printf("\n+--------------------------------------------------------------------+\n");
                    printf("| [!] Falha critica: ID do produto inexistente na base de dados.     |\n");
                    printf("+--------------------------------------------------------------------+\n");
                }
                break;
            }
            
            case 5: {
                printf("\n+--------------------------------------------------------------------+\n");
                printf("|                      MEU CARRINHO DE COMPRAS                       |\n");
                printf("+--------------------------------------------------------------------+\n");
                float total = exibir_carrinho_e_calcular_total(carrinho);
                if (total > 0) {
                    printf("|--------------------------------------------------------------------|\n");
                    printf("| TOTAL PARCIAL DA COMPRA: R$ %-38.2f |\n", total);
                }
                printf("+--------------------------------------------------------------------+\n");
                break;
            }
                
            case 6: {
                printf("\n+--------------------------------------------------------------------+\n");
                NoSimples acRemovida = pop_historico(&historico); // LIFO Pop
                
                if (acRemovida.produto.id != 0) {
                    remover_do_carrinho(&carrinho, acRemovida.produto.id);
                    
                    // Devolve o item ao controle de estoque logistico
                    NoArvore* pEstoque = buscar_bst(estoque, acRemovida.produto.id);
                    if (pEstoque != NULL) pEstoque->quantidadeEmEstoque += acRemovida.quantidade;
                    
                    printf("| [-] Desfeito: %2d unid. de %-25s devolvida!     |\n", 
                           acRemovida.quantidade, acRemovida.produto.nome);
                } else {
                    printf("| [!] Falha: Nada para desfazer. A pilha de historico esta vazia.    |\n");
                }
                printf("+--------------------------------------------------------------------+\n");
                break;
            }
            
            case 7: {
                printf("\n+--------------------------------------------------------------------+\n");
                float totalPedido = exibir_carrinho_e_calcular_total(carrinho);
                if (totalPedido > 0) {
                    Pedido novoPedido;
                    novoPedido.idPedido = id_gerador_pedidos++;
                    novoPedido.valorTotal = totalPedido;
                    
                    // Integra o Carrinho (Simples) com a Logistica (Fila)
                    enfileirar_pedido(&expedicao, novoPedido);
                    limpar_carrinho(&carrinho);
                    
                    // Garante que a pilha do historico seja limpa sem vazar memoria
                    while (pop_historico(&historico).produto.id != 0); 
                    
                    printf("|--------------------------------------------------------------------|\n");
                    printf("| [v] Compra finalizada! Pedido encaminhado para a logistica FIFO.   |\n");
                } else {
                    printf("| [!] Operacao abortada: Adicione itens na sacola antes de pagar.    |\n");
                }
                printf("+--------------------------------------------------------------------+\n");
                break;
            }
            
            case 8:
                printf("\n+--------------------------------------------------------------------+\n");
                printf("|                       LOGISTICA DE EXPEDICAO                       |\n");
                printf("+--------------------------------------------------------------------+\n");
                desenfileirar_pedido(&expedicao);
                printf("+--------------------------------------------------------------------+\n");
                break;
                
            case 0:
                printf("\n+--------------------------------------------------------------------+\n");
                printf("| Desligando modulos do SpringFit... Obrigado pela visita!           |\n");
                printf("+--------------------------------------------------------------------+\n\n");
                break;
                
            default:
                printf("\n+--------------------------------------------------------------------+\n");
                printf("| [!] Comando invalido. Por favor selecione uma tecla do menu.       |\n");
                printf("+--------------------------------------------------------------------+\n");
        }
    } while (opcao != 0);

    return 0;
}