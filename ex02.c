#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct lista{
    char nome[50];   // Aumentei o tamanho para suportar nomes maiores
    char email[50];  // Aumentei o tamanho para suportar emails maiores
    int telefone;
    struct lista *proximo;
} ListaTelefonica;

ListaTelefonica* inicializar();
ListaTelefonica* inserir(ListaTelefonica*);
void imprimir(ListaTelefonica*);

int main(){
    setlocale(LC_ALL, "Portuguese");
    ListaTelefonica * lista1;
    lista1 = inicializar();
    lista1 = inserir(lista1);
    imprimir(lista1);
}

ListaTelefonica* inicializar(){
    return NULL;
}

ListaTelefonica* inserir(ListaTelefonica* destino){
    ListaTelefonica* novo = (ListaTelefonica*) malloc(sizeof(ListaTelefonica));

    // Verifica se a alocação de memória foi bem-sucedida
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);  // Finaliza o programa em caso de erro
    }

    printf("Digite o nome a ser inserido: ");
    fgets(novo->nome, sizeof(novo->nome), stdin);  // Usando fgets ao invés de gets
    novo->nome[strcspn(novo->nome, "\n")] = '\0';  // Remove a nova linha inserida pelo fgets

    printf("Digite o email a ser inserido: ");
    scanf("%s", novo->email);  // Corrigido para não passar endereço desnecessário

    printf("Digite o telefone a ser inserido: ");
    scanf("%d", &novo->telefone);  // Corrigido o uso do operador &

    novo->proximo = destino;
    return novo;
}

void imprimir(ListaTelefonica* lista){
    ListaTelefonica* auxiliar;

    for (auxiliar = lista; auxiliar != NULL; auxiliar = auxiliar->proximo) {
        printf("\nNome: %s", auxiliar->nome);
        printf("\nEmail: %s", auxiliar->email);
        printf("\nTelefone: %d", auxiliar->telefone);
    }
}
