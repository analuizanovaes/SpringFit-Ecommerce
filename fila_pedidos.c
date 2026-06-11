/* 
====================================================================================================================================================================================
 * Estrutura: Fila (Queue) - Politica FIFO
 * A logistica do site dita a necessidade da Fila. Precisamos de justica: o cliente que finalizou a compra primeiro (First In) tem que ser o primeiro a ter o pacote despachado nos correios (First Out)."
=====================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "fila_pedidos.h"

/* Zera os apontadores da cabeca e da cauda da fila */
void inicializar_fila(FilaExpedicao* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

/* Operacao ENQUEUE: Entra no fim da fila */
void enfileirar_pedido(FilaExpedicao* f, Pedido ped) {
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    if (novo == NULL) return;
    
    novo->pedido = ped;
    novo->proximo = NULL; 

    if (f->fim == NULL) {
        f->inicio = novo; 
    } else {
        f->fim->proximo = novo; 
    }
    f->fim = novo; 
}

/* Operacao DEQUEUE: O logistico processa o no do inicio e destrói o nó */
void desenfileirar_pedido(FilaExpedicao* f) {
    if (f->inicio == NULL) {
        printf("| [!] Nao existem pedidos pendentes na fila logistica.               |\n");
        return;
    }
    
    NoFila* temp = f->inicio;
    f->inicio = f->inicio->proximo; 
    
    if (f->inicio == NULL) {
        f->fim = NULL; // Aterramento necessario se a fila secar
    }
    
    printf("| [v] Pedido #%-4d faturado e liberado para envio aos correios!      |\n", 
           temp->pedido.idPedido);
           
    free(temp); 
}