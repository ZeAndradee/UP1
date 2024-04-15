//Aluno: José Vinícius do Carmo de Andrade | 1232301920
#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int valor, prioridade;
    struct Elemento *prox;
}Elemento;

typedef struct Fila{
    struct Elemento *inicio;
    struct Elemento *fim;
}Fila;

Elemento *aux;

Fila *criar_fila(){
    Fila *nova_fila = (Fila*) malloc(sizeof(Fila));
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    
    return nova_fila;
}

void *inserir_fila(Fila *fi, int valor){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->prox = NULL;
    novo->prioridade = 0;
    
    if(fi->inicio == NULL){
        fi->inicio = novo;
        fi->fim = novo;
    }else{
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    printf("\n\nElemento %d, inserido sem prioridade.", novo->valor);
}

void inserir_prioridade(Fila *fi, int valor, int prioridade){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->prioridade = prioridade;
    novo->prox = NULL;
    
    if (fi->inicio == NULL || fi->inicio->prioridade < novo->prioridade){
        novo->prox = fi->inicio;
        fi->inicio = novo;
        if(fi->fim == NULL){
            fi->fim = novo;
        }
        printf("\n\nElemento %d, foi inserido com prioridade.", novo->valor);

    }else{
        aux = fi->inicio;
        while(aux != NULL && aux->prox->prioridade >= novo->prioridade){
            aux = aux->prox;
        }
            novo->prox = aux->prox;
            aux->prox = novo;
    }
}

void excluir_maior_prioridade(Fila *fi){
    if(fi->inicio == NULL){
        printf("\n\nA fila esta vazia.");
    }else{
        aux = fi->inicio;
        fi->inicio = aux->prox;
        printf("\n\nO elemento %d, de mais alta prioridade, foi excluido.", aux->valor);
        free(aux);
    }
}

void exibir_fila(Fila *fi){
    aux = fi->inicio;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

int main()
{
    Fila *fi = criar_fila();
    
    inserir_fila(fi, 10);
    inserir_fila(fi, 15);
    inserir_fila(fi, 1);
    
    inserir_prioridade(fi, 60, 10);
    inserir_prioridade(fi, 50, 8);
    inserir_prioridade(fi, 20, 9);
    
    printf("\n\n");
    exibir_fila(fi);
    
    excluir_maior_prioridade(fi);
    
    printf("\n\n");
    exibir_fila(fi);

    return 0;
}
