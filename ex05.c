#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaração da Lista
typedef struct produto{
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;

    struct pruduto *proximo;
} Produto;

//Inicialização da Lista
Produto* inicializar(){
    return NULL;
}

//Inserção
Produto* inserir(Produto* destino){
    system("clear");

    Produto* novo = (Produto*) malloc(sizeof(Produto));

    printf("Digite o codigo do produto: ");
    scanf("%d", &novo->codigo);
    fflush(stdin);

    printf("Digite a descrição do produto: ");
    fgets(novo->descricao, sizeof(novo->descricao), stdin);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &novo->quantidade);

    printf("Digite o valor do produto: ");
    scanf("%f", &novo->valor);

    novo -> proximo = destino;

    system("read -p \"\" dummy"); //Confirmação cpm Enter

    return novo;
}

//Impressão
void imprimir(Produto* produto){
    system("clear");

    Produto* auxiliar;

    for(auxiliar = produto; auxiliar != NULL; auxiliar = auxiliar -> proximo){
        printf("\nCodigo: %d", auxiliar -> codigo);
        printf("\nDescricao: %s", auxiliar -> descricao);
        printf("\nQuantidade: %d", auxiliar -> quantidade);
        printf("\nValor: %f", auxiliar -> valor);
    }
    system("read -p \"\" dummy");
}

//Busca
void consultarProduto(Produto *estoque){
    system("clear");

    Produto *auxiliar;
    int codigo;

    printf("\n------------------------------------------------------------");
    printf("\n-------------------Consulta de Produto----------------------");
    printf("\n------------------------------------------------------------");
    printf("\nDigite o código do produto: ");
    scanf("%d", &codigo);

    for(auxiliar = estoque; auxiliar != NULL; auxiliar = auxiliar -> proximo){
        if(auxiliar -> codigo == codigo){
            printf("\nProduto encontrado");

            return;
        }
    }
    printf("Produto não encontrado");
    system("read -p \"\" dummy");
}

Produto* removerProdutos(Produto *estoque){
    system("clear");

    Produto* anterior;
    Produto* auxiliar;
    int codigo;

    printf("\n-------------------------------------------");
    printf("\n------------Remoção de produto------------");
    printf("\n------------Digite o código do produto: ");
    scanf("%d", &codigo);

    for(anterior = NULL, auxiliar = estoque; auxiliar != NULL && auxiliar -> codigo != codigo; anterior = auxiliar, auxiliar = auxiliar -> proximo){

    }

    if(auxiliar == NULL){
        printf("Produto nao cadastrado");
        return estoque;
    }

    if(anterior == NULL){
        estoque = auxiliar -> proximo;
    }

    else{
        anterior -> proximo = auxiliar -> proximo;
    }

    printf("\nProduto removido!\n\n");
    system("read -p \"\" dummy");
    return estoque;
}


int main(){
    Produto* estoque;
    estoque = inicializar();
    int menu = -1;
    printf("\033[1;31m");
    
    while(menu != 0){

        printf("\n------------------------------------------------------------");
        printf("\n------------------Controle de Estoque-----------------------");
        printf("\n------------------------------------------------------------\n");

        printf("1 - Cadastrar Produtos\n");
        printf("2 - Consultar Produtos\n");
        printf("3 - Relatorio de Produtos\n");
        printf("4 - Consultar Volume em Estoque\n");
        printf("5 - Remover Produtos\n");
        printf("0 - Sair\n");

        printf("\n------------------------------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            estoque = inserir(estoque);
            break;
        case 2:
            consultarProduto(estoque);
            break;
        case 3:
            imprimir(estoque);
            break;
        case 5: 
            estoque = removerProdutos(estoque);
            break;
        case 0:
            printf("\nSaindo do Programa\n");
            system("read -p \"\" dummy");
            break;
        default:
            printf("\nOpcao Invalida");
            break;
        }
        system("clear");
    }
    return 0;
}