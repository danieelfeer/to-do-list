#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Tarefa{
    char titulo[50];
    char descricao[100];
    bool concluida; 
} typedef Tarefa;

Tarefa *listaTarefas = NULL;
int numTarefas = 0;  

void CriarNovaTarefa (){
    listaTarefas = (Tarefa*)realloc(listaTarefas, (numTarefas + 1)*sizeof(Tarefa));

    if (listaTarefas == NULL){
        printf("Erro na alocação\n");
        return;
    }

    Tarefa *novaTarefa = &listaTarefas[numTarefas++];
    novaTarefa->concluida = false;
    
    printf("Titulo: ");
    fgets(novaTarefa->titulo, 50, stdin);

    printf("Descricao: ");
    fgets(novaTarefa->descricao, 100, stdin);
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

void TarefasConcluidas(){
    MostrarTarefas();
    
    int indice;

    printf("Tarefa Concluida:\n");
    scanf("%d", &indice);
    getchar();

    char string[] = "marcar como concluida";
    Verificacao(string);

    if (indice >= 1 && indice <= numTarefas) {
        listaTarefas[indice - 1].concluida = true;
        printf("Tarefa marcada como concluida!\n");
    } else {
        printf("Indice invalido\n");
    }
    
}

void MostrarTarefasConcluidas(){
    printf("Tarefas Concluidas:\n");

    for(int i = 0; i < numTarefas; i++){
        
        if(listaTarefas[i].concluida == true){
            printf("Tarefa %d:\n", i + 1);
            printf("Titulo: %s", listaTarefas[i].titulo);
            printf("Descricao: %s", listaTarefas[i].descricao);
            printf("\n");
        }
    }
}

void MostrarTarefasNaoConcluidas(){
    printf("Tarefas Nao Concluidas:\n");

    for(int i = 0; i < numTarefas; i++){
        
        if(listaTarefas[i].concluida == false){
            printf("Tarefa %d:\n", i + 1);
            printf("Titulo: %s", listaTarefas[i].titulo);
            printf("Descricao: %s", listaTarefas[i].descricao);
            printf("\n");
        }
    }
}

void RemoverTarefa(){
    MostrarTarefas();
    int indice;
    printf("tarefa para remover\n");
    scanf("%d", &indice);
    getchar(); 

    char string[] = "Remover";
    Verificacao(string);

    if(indice >= 0 && indice < numTarefas + 1){

        for(int i = indice - 1; i < numTarefas; i++){
            listaTarefas[i] = listaTarefas[i + 1];
        }
        numTarefas--;
        printf("Tarefa removida!\n");
    } else{
        printf("Erro");
    }
}

void LiberarMemoria(){
    free(listaTarefas);
}

void Verificacao(char* string){
    char opcao;
    printf("Deseja %s a tarefa?\n", string);
    printf("1. Sim\n2. Nao\n");
    scanf("%c", &opcao);
    getchar();
    if (opcao == '1'){
        printf("Ok\n");
    } else{
        printf("Cancelado\n");
        return main();
    }
}

int main(){

    int opcao;

    do{    
        printf("1. Criar Tarefa\n");
        printf("2. Mostar Tarefas\n");
        printf("3. Marcar como Concluida\n");
        printf("4. Nao Conluidas\n");
        printf("5. Concluidas\n");
        printf("6. Remover Tarefa\n");
        

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
            TarefasConcluidas();
            break;    
        case 4:
            MostrarTarefasNaoConcluidas();
            break;    
        case 5:
            MostrarTarefasConcluidas();
            break;
        case 6:
            RemoverTarefa();
            break;
        break;    
        
        default:
            printf("Opcao invalida\n");
            break;
        }

    } while(opcao != 0);

    LiberarMemoria();

    return 0;  
}

