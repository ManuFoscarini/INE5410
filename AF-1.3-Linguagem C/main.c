#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"

/// Reserva uma região de memória capaz de guardar capacity ints e
/// inicializa os atributos de b
void init_buffer(buffer_t* b, int capacity) {
    b->data = (int *) malloc(capacity * sizeof(int));
    b->capacity = capacity;
    b->take_idx = 0;
    b->put_idx = 0;
    b->size = 0;
}

/// Libera a memória e quaisquer recursos de propriedade de b. Desfaz o
/// init_buffer()
void destroy_buffer(buffer_t* b) {
    free(b->data);
}

/// Retorna o valor do elemento mais antigo do buffer b, ou retorna -1 se o
/// buffer estiver vazio
int take_buffer(buffer_t* b) {
    if (b->size == 0) {
        return -1;
    }
    int papel_idx = b->take_idx;
    b->size--;
    if (b->take_idx == b->capacity-1){
        b->take_idx = 0;
    }
    else{
        b->take_idx++;
    }
    return b->data[papel_idx];
}

/// Adiciona um elemento ao buffer e retorna 0, ou retorna -1 sem
/// alterar o buffer se não houver espaço livre
int put_buffer(buffer_t* b, int val) {
    if (b->size == b->capacity){
        return -1;
    }
    int papel_idx = b->put_idx;
    b->size++;
    if (b->put_idx == b->capacity-1){
        b->put_idx = 0;
    }
    else{
        b->put_idx++;
    }

    b->data[papel_idx] = val;
    return 0;
}

/// Lê um comando do terminal e o executa. Retorna 1 se o comando era
/// um comando normal. No caso do comando de terminar o programa,
/// retorna 0
int ler_comando(buffer_t* b);


int main(int argc, char **argv) {

    int capacity = 0;
    printf("Digite o tamanho do buffer:\n>");
    if (scanf("%d", &capacity) <= 0) {
        printf("Esperava um número\n");
        return 1;
    }
    buffer_t b;
    init_buffer(&b, capacity);
    
    printf("Comandos:\n"
           "r: retirar\n"
           "c: colocar\n"
           "q: sair\n\n");
    
    while(1) {
        int comando = ler_comando(&b);
        if (comando == 0) {
            break;
        }
    }

    // *** ME COMPLETE ***

    destroy_buffer(&b);
    return 0;
}