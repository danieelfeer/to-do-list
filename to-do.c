#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Tarefa{
    char titulo[50];
    char descricao[100];
    int prioridade; 
} typedef Tarefa;

Tarefa listaTarefas[100];
int numTarefas = 0;  

void CriarNovaTarefa (){
    Tarefa tarefa;
    
    printf("Titulo: ");
    fgets(tarefa.titulo, 50, stdin);

    printf("Descricao: ");
    fgets(tarefa.descricao, 100, stdin);

    listaTarefas[numTarefas++] = tarefa;
    
}

void MostrarTarefas(){
    printf("Tarefas criadas:\n");
    for (int i = 0; i < numTarefas; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Titulo: %s", listaTarefas[i].titulo);
        printf("Descricao: %s", listaTarefas[i].descricao);
        printf("\n");
    }
}

void RemoverTarefa(){
    MostrarTarefas();
    int indice;
    printf("tarefa para remover\n");
    scanf("%d", &indice);
    getchar();

    if(indice >= 0 && indice < numTarefas){
        for(int i = indice - 1; i < numTarefas - 1; i++){
            listaTarefas[i] = listaTarefas[i + 1];
        }
        numTarefas--;
        printf("Tarefa removida!\n");
    } else{
        printf("Erro");
    }
}

int main(){

    int opcao;

    do{    
        printf("1. Criar Tarefa\n");
        printf("2. Mostar Lista\n");
        printf("3. Remover Tarefa\n");

        scanf("%d", &opcao);
        getchar();

        switch (opcao){
        case 1:
            CriarNovaTarefa();
            break;
        case 2:
            MostrarTarefas();
            break;
        case 3:
            RemoverTarefa();
            break;    
        default:
            printf("Opcao invalida\n");
            break;
        }

    } while(opcao != 0);

}

