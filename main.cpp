#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int estado;
    struct Paciente *prox;
}
        Paciente;

typedef struct{
    Paciente *inicio;
    Paciente *fim;
    int tamanho;
}
        Fila;

void IniciaFila(Fila *fila){
    fila->fim = NULL;
    fila->inicio = NULL;
    fila->tamanho = 0;
}

int Vazia(Fila *fila){
    return(fila->fim == NULL);
}

void Enfila(int x, Fila *fila){

    Paciente *pac1, *pac2;

    pac1 = (Paciente *) malloc(sizeof(Paciente));
    pac2 = (Paciente *) malloc(sizeof(Paciente));

    pac2->estado = x;
    pac2->prox = NULL;

    if (fila->fim == NULL){
        fila->inicio = pac1;
    }
    else{
        fila->fim->prox = pac1;
        pac1 = pac1->prox;
        pac1->prox = x;
    }
}

void inserir_prioridade_alta(Fila *fila, Paciente *paciente){
    Paciente *pac1, *pac2;

    pac1 = (Paciente *) malloc(sizeof(Paciente));
    pac2 = (Paciente *) malloc(sizeof(Paciente));

    pac2->estado = x;
    pac2->prox = NULL

    if(fila->fim == NULL){
        fila->inicio = pac1;
    }
    else{
        if(x>2){
            if(fila->inicio->estado<3){
                pac1->estado = fila->inicio;
                fila->inicio = pac1;
            }
            else{
                pac1 = fila->inicio;
                while(pac1->prox && pac1->prox->estado > 2){
                    pac1 = pac1->prox;
                    pac2->prox = pac1->prox;

                }
            }
        }
        else {
            pac1 = fila->fim;
            while (pac1->prox){
                pac1 = pac1->prox;
                pac1->prox = pac2;
            }
        }

    }
}

void inserir_prioridade_media (Paciente Fila *fila, int grav){
Paciente *pac1, *pac2;

pac1 = (Paciente *) malloc(sizeof(Paciente));
pac2 = (Paciente *) malloc(sizeof(Paciente));

pac2->estado = x;
pac2->prox = NULL

if (fila->fim == NULL){
fila->inicio = pac1;
}
else{
if(x>1){
if(fila->inicio->estado<2){
pac1->estado = fila->inicio;
fila->inicio = pac1;
}
else{
pac1 = fila->inicio;
while(pac1->prox && pac1->prox->estado > 2){
pac1 = pac1->prox;
pac2->prox = pac1->prox;

}

}
}
else {
pac1 = fila->fim;
while (pac1->prox){
pac1 = pac1->prox;
pac1->prox = pac2;
}
}

}
}

int Desenfila(Fila *fila){
    Paciente *q;
    int v;

    if(Vazia(fila)){
        printf("Fila vazia \n\n");
        return 0;
    }

    q = fila->inicio;
    v = q->estado;
    fila->inicio = q->prox;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    free(q);
    fila->tamanho--;
    return v;
}

void imprimir_inicio_ao_fim(Fila *fila){
    if (fila->inicio == NULL){
        printf("\nFila Vazia!!");
    }
    else{
        pac1 = fila->inicio;
        do{
            printf(" %d ", pac1->num);
            pac1 = pac1->prox;
        }while(pac1 != NULL);
    }
}

int main(){
    Paciente estado, nome;

    printf("Nome do paciente: ");
    scanf("%s", &nome);

    do{
        printf("\n Selecione o estado do paciente: \n1 - pouco urgente \n2 - urgente \n3 - muito urgente \n\n");
        scanf ("%d", &estado);
    } while ((estado != 1) && (estado != 2) && (estado != 3));

    switch(estado){
        case 1:
            Enfila(nome, &fila);
            break;

        case 2:
            inserir_prioridade_media(nome, &fila);
            break;

        case 3:
            inserir_prioridade_alta(nome, &fila);
            break;
        default:
            printf("erro");
    }

    printf("Fila de espera completa e em ordem de prioridade: \n")
    imprimir_inicio_ao_fim(fila);
}