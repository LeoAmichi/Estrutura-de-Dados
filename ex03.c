#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct produto{
    int codigo;
    int qtd;
    char nome[20];
    struct produto *proximo;
} Produto;

Produto* inicializar(){
    return NULL;
}

Produto* inserir(Produto* destino){
    Produto* novo = (Produto*) malloc(sizeof(Produto));
    printf("Digite o nome do produto a ser inserido na lista de compra: ");
    gets(novo -> nome);
    printf("Digite o codigo do produto a ser inserido: ");
    scanf("%d", &novo -> codigo);
    printf("Digite a qtd desse produto a ser adicionado na lista de compra: ");
    scanf("%d", &novo -> qtd);
    fflush(stdin);

    novo -> proximo = destino;
    return novo;
}

void imprimir(Produto* lista){
    Produto* aux;

    for(aux=lista; aux != NULL; aux = aux -> proximo){
        printf("Nome: %s", aux -> nome);
        printf("Quantidade: %d", aux -> qtd);
        printf("Codigo: %d", aux -> codigo);
    }
}

int main(){
    Produto *lista_compras;
    lista_compras = inicializar();
    lista_compras = inserir(lista_compras);
    imprimir(lista_compras);
}