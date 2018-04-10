/*
Trabalho 8 - Questão 2

Autor:        Wernen da Silva Veiga – 15231615

2. Cadastre 5 números em uma fila dinâmica e mais 5 em uma pilha dinâmica. Em seguida, mostre três relatórios.
1º) os números que estão nas duas estruturas.
2º) os que estão na fila.
3º) os que estão na pilha.
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct no{
    int dado;
    struct no *prox;
}TNo;

typedef struct fila{
    struct no *inicio;
    struct no *final;
    int tamanho;
}TFila;

typedef struct pilha{
    struct no *topo;
    int tamanho;
}TPilha;

void cria_fila(TFila *F){
    F->inicio= NULL;
    F->final= NULL;
    F->tamanho = 0;
}
int fila_vazia(TFila *F){
    return(F->inicio == NULL && F->final == NULL);
    }

void cria_pilha(TPilha *Pi){
    Pi->topo = NULL;
    Pi->tamanho = 0;
}
int Pilha_vazia(TPilha *pi){
    return (pi->topo == NULL);
}
int cadastrar_fila(TFila *F, int num){

   if(F->tamanho >= 5 ) return 0;

        TNo *novo;
        novo = (TNo*)malloc(sizeof(TNo));
            if(novo == NULL) printf("Erro na alocacao!\n");
                novo->dado = num;
                novo->prox = NULL;
                if(fila_vazia(F))
                    F->inicio = novo;
                    else
                        (F->final)->prox = novo;
                    F->final= novo;

                    return  F->final->dado;
}
void mostrar_fila(TFila *F){

    if(fila_vazia(F)) printf("\nFila Vazia!");

        TNo *aux;
        for(aux=F->inicio; aux != NULL; aux = aux->prox){
        	printf("|%d|", aux->dado);
		}
}
int cadastrar_pilha(TPilha* pi, int num){

        if(pi->tamanho>=MAX) return 0;

            TNo *novo;
            novo = (TNo*)malloc(sizeof(TNo));
                if(novo == NULL) printf("Erro na alocacao!\n");
                    novo->dado = num;
                    novo->prox = pi->topo;
                    pi->topo = novo;
                    //tamanho da pilha vai ser incrementado fora da função
            return pi->topo->dado;
}
void mostrar_pilha(TPilha *pi){

    if(Pilha_vazia(pi)) printf("\nPilha Vazia!");

        TNo *aux;
        printf("\n _ \n");
        for(aux=pi->topo; aux!= NULL; aux= aux->prox){
        	printf("|%d|\n", aux->dado);
		}
}

int main(){
        TFila *F;
        TPilha *Pi;
        int op, i, num_c, opm;
        F = (TFila*) malloc(sizeof(TFila));
        Pi = (TPilha*)malloc(sizeof(TPilha));

        cria_fila(F);
        cria_pilha(Pi);

        do{
            printf("\n------------MENU-----------\n");
            printf("1- Cadastrar Numero na Fila.\n");
            printf("2- Cadastrar Numero na Pilha.\n");
            printf("3- Mostrar Relatorio somente da Fila.\n");
            printf("4- Mostrar Relatorio somente da Pilha.\n");
            printf("5- Mostrar Relatorio da Fila e Pilha. \n");
            printf("6- Sair.\n\n");
            printf("Digite a opcao: ");
            scanf("%d", &op);
            if (op != 6){
                switch (op){
                    case 1: for(F->tamanho; F->tamanho<MAX; F->tamanho++){//tamanho da fila vai ser incrementado for
                                printf("\nDigite o numero a ser cadastrado: ");
                                scanf("%d", &num_c);
                                printf("\nNumero %d cadastrado com sucesso!\n",cadastrar_fila(F, num_c));
                            }
                            printf("\nFila Cheia!\n");
                    break;


                    case 2: for(Pi->tamanho; Pi->tamanho<MAX; Pi->tamanho++){//o tamanho da pilha vai ser incrementado for
                                printf("\nDigite o numero a ser cadastrado: ");
                                scanf("%d", &num_c);
                                printf("\nNumero %d cadastrado com sucesso!\n",cadastrar_pilha(Pi, num_c) );
                            }
                            printf("\nPilha Cheia!\n");
                    break;

                    case 3:
                            mostrar_fila(F);
                    break;

                    case 4:
                            mostrar_pilha(Pi);
                    break;

                    case 5:
                            mostrar_fila(F);
                            mostrar_pilha(Pi);
                    break;

                default: printf("Opcao Invalida!\n");
            }
        }
    }while(op !=6);
}
