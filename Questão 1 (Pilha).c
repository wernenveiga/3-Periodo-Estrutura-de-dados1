/*
Trabalho 8 - Questão 1

 Autor:       Wernen da Silva Veiga – 15231615
 
1. Apresente o menu de opções abaixo:
1 – Cadastrar número
2 – Mostrar números pares
3 – Excluir número
4 – Sair
Observações:
a) Implemente usando uma estrutura tipo pilha.
b) Quando a opção 1 do menu for solicitada, só deve parar de cadastrar quando o usuário pressionar uma letra.
c) Mostrar mensagem para opção invalidade do menu.
d) Quando a opção do menu não puder ser realizada, mostrar mensagem.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct No{
    int dado;
    struct No *prox;
} TNo;

typedef struct Pilha{
    struct No *topo;
    int tamanho;
} TPilha;

void inicia_pilha(TPilha *pilha){
    pilha->topo = NULL;
    pilha->tamanho = 0;
}
int Pilha_vazia(TPilha *pilha){
    return(pilha->topo == NULL);
}

int comapara_letra(char *s){//função que vai ficar comparando se o usuário digitou uma letra pra poder retornar ao menu
        char letras [27] = "qwertyuiopasdfghjklzxcvbnm";
        int i;
        for(i=0; i<27; i++){
            if(*s == letras[i])
                return 1;
        }
        return 0;
}
int cadastrar_numero(TPilha* pilha, int num){
        TNo *novo;
        novo = (TNo*)malloc(sizeof(TNo));
            if(novo == NULL) printf("Erro na alocacao!\n");
            novo->dado = num;
            novo->prox = pilha->topo;
            pilha->topo = novo;
            pilha->tamanho++;

            return  pilha->topo->dado;
}
void mostrar_pares(TPilha *pilha){

    if(Pilha_vazia(pilha)) printf("Pilha Vazia!");

        TNo *aux;
        printf(" _ \n");
        for(aux=pilha->topo; aux!= NULL; aux= aux->prox){
        	if(aux->dado % 2 == 0)
        	printf("|%d|\n", aux->dado);
		}
}

int excluir_num(TPilha* pilha){
    if(Pilha_vazia(pilha))
        printf("Pilha vazia!\n");
    else{
        TNo *retira;
        int valor;
        retira = pilha->topo;
        pilha->topo = retira->prox;
        valor = retira->dado;
        free(retira);
        pilha->tamanho--;
        return  valor;
    }
}

int menu(TPilha *pilha){
int op, num_int;
    char num_char[4];
    do{
    printf("------------MENU-----------\n");
    printf("1- Cadastrar Numero.\n");
    printf("2- Mostrar Numeros Pares.\n");
    printf("3- Exluir Numero.\n");
    printf("4- Sair.\n\n");
    printf("Digite a opcao: ");
    scanf("%d", &op);
        if (op != 4){
            switch (op){

                case 1:    printf("\nPara retornar ao Menu digite qualquer letra.\n ");
                            do{
                                printf("\nDigite o numero a ser cadastrado: ");
                                scanf("%s", num_char);
                                if(!comapara_letra(num_char)){
                                    num_int = atoi(num_char);//A função atoi que transforma caracter em inteiro
                                    printf("\nNumero %d cadastrado com sucesso!\n", cadastrar_numero(pilha, num_int));
                                }
                            }while(!comapara_letra(num_char));
                break;


                case 2: mostrar_pares(pilha);
                        system("pause");
                    break;

                case 3:
                        printf("\nNumero %d exluido da pilha!\n",excluir_num(pilha));
                    break;

                default: printf("Opcao Invalida!\n");
            }
        }
    }while(op !=4);
    return 1;
}
int main(){
    TPilha *pilha;
    pilha = (TPilha *) malloc (sizeof(TPilha));
    inicia_pilha(pilha);
    menu(pilha);

}
