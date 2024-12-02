#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct agenda{
    char compromisso[30];
    int dataInicial;
    int prazoFinal;

    struct agenda* proximo;

} Agenda;

Agenda* inicializar(){
    return NULL;
}

Agenda* inserir(Agenda* destino){
    Agenda* novo = (Agenda*) malloc(sizeof(Agenda));

    printf("Digite o compromisso a ser inserido: ");
    fgets(novo -> compromisso, 30, stdin);
    printf("Digite a data inicial que você agendou: ");
    scanf("%d", &novo -> dataInicial);
    printf("Digite a data final do compromisso: ");
    scanf("%d", &novo -> prazoFinal);

    novo -> proximo = destino;
    return novo;
}


void imprimir(Agenda* agendaCompromisso){
    Agenda* auxiliar;

    for(auxiliar = agendaCompromisso; auxiliar != NULL; auxiliar = auxiliar -> proximo){

        printf("\nCompromisso: %s", auxiliar -> compromisso);
        printf("Data Inicial: %d", auxiliar -> dataInicial);
        printf("\nPrazo Final: %d\n", auxiliar -> prazoFinal);
    }
}


int main(){
    Agenda* agendaCompromisso;
    agendaCompromisso = inicializar();
    agendaCompromisso = inserir(agendaCompromisso);
    imprimir(agendaCompromisso);
    return 0;
}

