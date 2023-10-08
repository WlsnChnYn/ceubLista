#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente {
    char nome[50];
    int estado;
    paciente *prox;
} Paciente;

typedef struct{
    Paciente *inicio;
    Paciente *fim;
    int tamanho;
} Fila;

void IniciaFila(Fila *fila){
    fila->fim = NULL;
    fila->inicio = NULL;
    fila->tamanho = 0;
}

int Vazia(Fila *fila){
    return(fila->fim == NULL);
}

void Enfila(Paciente *paciente, Fila *fila){

    if (Vazia(fila)) {
        fila->inicio = paciente;
    } else {
        fila->fim->prox = paciente;
    }

    fila->fim = paciente;
    fila->tamanho++;
}

//void inserir_prioridade_alta(Fila *fila, Paciente *paciente){
//    Paciente *novo = malloc(sizeof(Paciente));
//    Paciente *existente;
//
//    existente = fila->inicio;
//    pac2 = (Paciente *) malloc(sizeof(Paciente));
//
//    pac2->estado = x;
//    pac2->prox = NULL
//
//    if(fila->fim == NULL){
//        fila->inicio = existente;
//    }
//    else{
//        if(x>2){
//            if(fila->inicio->estado<3){
//                existente->estado = fila->inicio;
//                fila->inicio = existente;
//            }
//            else{
//                existente = fila->inicio;
//                while(existente->prox && existente->prox->estado > 2){
//                    existente = existente->prox;
//                    pac2->prox = existente->prox;
//
//                }
//            }
//        }
//        else {
//            existente = fila->fim;
//            while (existente->prox){
//                existente = existente->prox;
//                existente->prox = pac2;
//            }
//        }
//
//    }
//}

//void inserir_prioridade_media (Paciente ,Fila *fila){
//Paciente *pac1, *pac2;
//
//pac1 = (Paciente *) malloc(sizeof(Paciente));
//pac2 = (Paciente *) malloc(sizeof(Paciente));
//
//pac2->estado = x;
//pac2->prox = NULL
//
//if (fila->fim == NULL){
//fila->inicio = pac1;
//}
//else{
//if(x>1){
//if(fila->inicio->estado<2){
//pac1->estado = fila->inicio;
//fila->inicio = pac1;
//}
//else{
//pac1 = fila->inicio;
//while(pac1->prox && pac1->prox->estado > 2){
//pac1 = pac1->prox;
//pac2->prox = pac1->prox;
//
//}
//
//}
//}
//else {
//pac1 = fila->fim;
//while (pac1->prox){
//pac1 = pac1->prox;
//pac1->prox = pac2;
//}
//}
//
//}
//}

void Desenfila(Fila *fila){
    Paciente *q;
    int v;

    if(Vazia(fila)){
        printf("Fila vazia \n\n");
        return;
    }

    q = fila->inicio;
    fila->inicio = q->prox;
    printf("# Prioridade %d: %s \n", q->estado, q->nome);

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    free(q);
    fila->tamanho--;
}

void imprimir_inicio_ao_fim(Fila *fila) {
    Paciente *pac;
    if (Vazia(fila)) {
        printf("\nFila Vazia!!");
    } else {
        printf("Fila de espera completa e em ordem de prioridade: \n");
        pac = fila->inicio;
        while (pac != NULL) {
            printf("# %d - %s\n", pac->estado, pac->nome);
            pac = pac->prox;
        }
    }
}

int main(){
    Paciente *paciente;
    char nome[30];
    int estado, i, max = 2;
    Fila fila;

    IniciaFila(&fila);

    for (i=0; i<max; i++){
        paciente = (Paciente *) malloc(sizeof(Paciente));
        paciente->prox = NULL;

        printf("\nNome do paciente:\n");
        scanf("%s", &nome);
        strcpy(paciente->nome, nome);

        do {
            printf("\n Selecione o estado do paciente: \n1 - pouco urgente \n2 - urgente \n3 - muito urgente \n\n");
            scanf("%d", &estado);
        } while ((estado != 1) && (estado != 2) && (estado != 3));
        paciente->estado = estado;

        switch (estado) {
            case 1:
            case 2:
            case 3:
                Enfila(paciente, &fila);
                break;

//            case 2:
//                inserir_prioridade_media(&paciente, &fila);
//                break;
//
//            case 3:
//                inserir_prioridade_alta(&paciente, &fila);
//                break;
            default:
                printf("erro");
        }
    };

    printf("\nFIM DA ENTRADA (atendendo por ordem de prioridade)\n\n");

    do {
        Desenfila(&fila);
    } while (!Vazia(&fila));

}