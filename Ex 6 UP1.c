//Aluno: José Vinícius do Carmo de Andrade | 1232301920
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *esq,*dir;
}No;


typedef struct Arvore{
    struct No *raiz;
}Arvore;

Arvore *cria_arvore(){
    Arvore *nova_arvore = (Arvore*) malloc(sizeof(Arvore));
    nova_arvore->raiz = NULL;
    return nova_arvore;
}

No *cria_elemento(int valor){
    No *novo_elemento = (No*) malloc(sizeof(No));
    novo_elemento->valor = valor;
    novo_elemento->esq = NULL;
    novo_elemento->dir = NULL;
    
    return novo_elemento;
}

void inserir_elemento(Arvore *arvore, int valor){
    No *novo = cria_elemento(valor);
    if(arvore->raiz == NULL){
        arvore->raiz = novo;
        return;
    }
    
    No *atual = arvore->raiz;
    No *pai = NULL;
    
    while(atual != NULL){
        pai = atual;
        if(valor < atual->valor){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }
    
    if(valor < pai->valor){
        pai->esq = novo;
    }else{
        pai->dir = novo;
    }
}

void exibe_arvore(No *no){
    if(no != NULL){
        printf("%d ", no->valor);
        exibe_arvore(no->esq);
        exibe_arvore(no->dir);
    }
}

int count = 0;
int nao_folha(No *no){
    if(no != NULL){
        if(no->esq != NULL || no->dir != NULL){
            count+=1;
        }
        nao_folha(no->esq);
        nao_folha(no->dir);
    }
    return count;
}

int main()
{
    Arvore *arvore = cria_arvore();
    
    inserir_elemento(arvore, 50);
    inserir_elemento(arvore, 45);
    inserir_elemento(arvore, 40);
    inserir_elemento(arvore, 35);
    inserir_elemento(arvore, 43);
    inserir_elemento(arvore, 48);
    inserir_elemento(arvore, 47);
    inserir_elemento(arvore, 49);
    inserir_elemento(arvore, 70);
    inserir_elemento(arvore, 65);
    inserir_elemento(arvore, 63);
    inserir_elemento(arvore, 66);
    inserir_elemento(arvore, 72);
    inserir_elemento(arvore, 71);
    inserir_elemento(arvore, 73);
    exibe_arvore(arvore->raiz);
    
    printf("\n\nNos nao-folha: %d", nao_folha(arvore->raiz));
}
