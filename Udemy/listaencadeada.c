#include <stdio.h>
#include <stdlib.h>

struct st_no{
    int valor;
    struct st_no *prox;
};

typedef struct st_no no;


int vazia(no *le){
    if(le->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

void inicia(no *le){
    le->prox = NULL;
}

void libera (no *le){
    if(!vazia(le)){
        no *proxNo, *atual;
        atual = le->prox;
        while(atual!= NULL){
            proxNo = atual->prox;
            free(atual);
            atual = proxNo;
        }
    }
}

void exibe(no *le){
    if(vazia(le)){
        printf("A Lista esta Vazia \n");
        return;
    }
    no *tmp;
    tmp = le->prox;

    while(tmp != NULL){
        printf("%d ", tmp->valor);
        tmp = tmp->prox;
    }
    printf("\n\n");
}

void insereinicio(no *le){
    no *novo = (no*) malloc(sizeof(no));
    if(!novo){
        printf("Sem memoria disponivel\n");
        exit(1);
    }
    printf("Informe o Valor: ");
    scanf("%d", &novo->valor);

    no *oldhead = le->prox;
    le->prox = novo;
    novo->prox = oldhead;
}

void inserefim(no *le){
    no *novo = (no*)malloc(sizeof(no));
    if(!novo){
        printf("Sem memoria disponivel\n");
        exit(1);
    }
    printf("Informe o Valor: ");
    scanf("%d", &novo->valor);
    novo->prox = NULL;

    if(vazia(le)){
        le->prox = novo;
    }else{
        no *tmp = le->prox;

        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
}

void opcao(no *le, int op){
    switch (op)
    {
    case 0:
        libera(le);
        break;
    case 1:
        exibe(le);
        break;
    case 2:
        insereinicio(le);
        break;
    case 3:
        inserefim(le);
        break;
    case 4:
        inicia(le);
        break;
    
    default:
        printf("Comando invalido\n\n");
        break;
    }
}

int menu(){
    int opt;

    printf("Escolha a opcao: \n");
    printf("0 - Sair\n");
    printf("1 - Exibir\n");
    printf("2 - Inserir no Inicio\n");
    printf("3 - Inserir no Fim\n");
    printf("4 - Zerar Lista(Reinicia Lista\n");
    printf("Opção: ");
    scanf("%d", &opt);

    return opt;
}

int main(){
    no *le = (no*)malloc(sizeof(no));

    if(!le){
        printf("Sem memoria disponivel\n");
        exit(1);
    }
    inicia(le);
    int opt;

    do{
        opt=menu();
        opcao(le, opt);
    } while (opt);
    free(le);
    return 0;
}