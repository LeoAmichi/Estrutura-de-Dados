#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaração da Lista
typedef struct produto{
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;

    struct produto *proximo;
} Produto;

typedef struct volumeEstoque{
    Produto;
} volumeEstoque;

//Inicialização da Lista
Produto* inicializar(){
    return NULL;
}

//Inserção
Produto* inserir(Produto* destino){
    system("clear");

    Produto* novo = (Produto*) malloc(sizeof(Produto));

    printf("\n------------------------------------------------------------");
    printf("\n--------------------Cadastro de Produto---------------------");
    printf("\n------------------------------------------------------------");

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &novo->codigo);
    getchar();

    printf("Digite a descricao do produto: ");
    fgets(novo->descricao, sizeof(novo->descricao), stdin);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &novo->quantidade);

    printf("Digite o valor do produto: ");
    scanf("%f", &novo->valor);

    novo -> proximo = destino;

   system("read -p \"\" dummy"); //Confirmação com Enter

    return novo;
}

//Impressão
void imprimir(Produto* produto){
    system("clear");

    Produto* auxiliar;

    for(auxiliar = produto; auxiliar != NULL; auxiliar = auxiliar -> proximo){
        printf("------------------------------------------------------------");
        printf("\nCodigo: %d", auxiliar -> codigo);
        printf("\nDescricao: %s", auxiliar -> descricao);
        printf("Quantidade: %d", auxiliar -> quantidade);
        printf("\nValor: %f\n", auxiliar -> valor);
        printf("------------------------------------------------------------\n");
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
    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    for(auxiliar = estoque; auxiliar != NULL; auxiliar = auxiliar -> proximo){
        if(auxiliar -> codigo == codigo){
            system("clear");
            printf("------------------------------------------------------------");
            printf("\nCodigo: %d", auxiliar -> codigo);
            printf("\nDescricao: %s", auxiliar -> descricao);
            printf("Quantidade: %d", auxiliar -> quantidade);
            printf("\nValor: %f\n", auxiliar -> valor);
            printf("------------------------------------------------------------\n");
            system("read -p \"\" dummy");
            return;
        }
    }
    printf("Produto não encontrado\n\n");
    system("read -p \"\" dummy");
}

//Remoção
Produto* removerProdutos(Produto *estoque){
    system("clear");

    Produto* anterior;
    Produto* auxiliar;
    int codigo;

    printf("\n------------------------------------------------------------");
    printf("\n--------------------Remocao de Produto----------------------");
    printf("\n------------------------------------------------------------");
    printf("\nDigite o código do produto: ");
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

    free(auxiliar);

    printf("\nProduto removido!\n\n");
    system("read -p \"\" dummy");
    return estoque;
}

//Controle de Estoque
void buscaEstoque(volumeEstoque** volume, Produto* estoque){
    system("clear");

    Produto* auxiliar;
    Produto* novoVolume = NULL;
    Produto* ultimoVolume = NULL;

    int qtd = 0;
    char menu;

    printf("\n------------------------------------------------------------");
    printf("\n--------------------Consulta de Volume----------------------");
    printf("\n------------------------------------------------------------");
    printf("\nDigite a quantidade minima de estoque: ");
    scanf("%d", &qtd);

    for(auxiliar = estoque; auxiliar != NULL; auxiliar = auxiliar -> proximo){
        if(auxiliar -> quantidade < qtd){
            Produto* novoProduto = (Produto*) malloc(sizeof(Produto));
            *novoProduto = *auxiliar; 
            novoProduto->proximo = NULL;

            if(novoVolume == NULL){
                novoVolume = novoProduto;
                ultimoVolume = novoProduto;
            }
            else{
                ultimoVolume -> proximo = novoProduto;
                ultimoVolume = novoProduto;
            }
        }
    }
    *volume = novoVolume;

    printf("\nDeseja verificar os produtos abaixo do minimo? S/N: ");
    getchar();
    scanf(" %c", &menu);  // Agora sem problemas de buffer
    if(menu == 'S' || menu == 's') {
        imprimirEstoqueAbaixo(*volume);
    } else {
        return;
    }
}

//Impressão da nova Lista com os produtos abaixo do estoque
void imprimirEstoqueAbaixo(Produto* volume){
    system("clear");

    Produto* auxiliar;

    for(auxiliar = volume; auxiliar != NULL; auxiliar = auxiliar -> proximo){
        printf("------------------------------------------------------------");
        printf("\nCodigo: %d", auxiliar -> codigo);
        printf("\nDescricao: %s", auxiliar -> descricao);
        printf("Quantidade: %d", auxiliar -> quantidade);
        printf("\nValor: %f\n", auxiliar -> valor);
        printf("------------------------------------------------------------\n");
    }
    system("read -p \"\" dummy");
}

//Main
int main(){
    Produto* estoque;
    estoque = inicializar();

    volumeEstoque* volume;
    volume = inicializar();
    
    printf("\033[31m");
    int menu = -1;
    
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

        printf("------------------------------------------------------------\n");
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
        case 4:
            buscaEstoque(&volume, estoque);
            break;
        case 5: 
            estoque = removerProdutos(estoque);
            break;
        case 0:
            printf("\nSaindo do programa...\n");
            system("read -p \"\" dummy");
            break;
        default:
            printf("\nOpcao Invalida");
            system("read -p \"\" dummy");
            break;
        }
        system("clear");
    }
    return 0;
}