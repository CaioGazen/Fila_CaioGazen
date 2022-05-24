#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "fila.h"

void cadastrar(struct sfila *campos_guarus,struct sfila *guarus_campos, int s){
    char placa[7];
    printf("\nInforme a placa do veiculo para cadastra-lo na travessia: ");
    scanf("%s",placa);
    switch (s){
        case 1:
            for (int i = 0; i <= 6; i++){
                enqueue(campos_guarus,placa[i]);
            }
            printf("\nO veiculo %s foi cadastrado no sentido Campos->Guarus\n",placa);
            break;
        case 2:
            for (int i = 0; i <= 6; i++){
                enqueue(guarus_campos,placa[i]);
            }
            printf("\nO veiculo %s foi cadastrado no sentido Guarus->Campos\n",placa);
            break;
    }
    printf("\nDeseja incluir novos carros (s/n)?");
    char e;
    scanf(" %c",&e);
    if(e == 's'){
        system("cls");
        printf("Em qual sentido deseja incluir novos carros?\n1 - Campos->Guarus\n2 - Guarus->Campos\n\n");
        scanf(" %d",&s);
        cadastrar(campos_guarus, guarus_campos,s);
    }
}

void liberar(struct sfila *campos_guarus,struct sfila *guarus_campos){
    char placa_campos[8] = "0000000";
    char placa_guarus[8] = "0000000";
    if (qisEmpty(campos_guarus) && qisEmpty(guarus_campos)){
        printf("\nSem carros para atravessar\n\n");
        system("pause");
        return;
    }
    printf("\nTravessia Liberada\n");
    if (!qisEmpty(campos_guarus)){
        for (int i = 0; i < 7; i++){
            placa_campos[i] = dequeue(campos_guarus);
        }
        placa_campos[8] = '\0';
        for(int i = 0; i < 49; i++){
            system("cls");
            printf("\nCarro %s atravessando sentido Campos->Guarus\n", placa_campos);
            printf("[");
            for(int j = 0; j < i; j++) {
                printf("=");
            }
            for(int h = 48;h > i; h--) {
                printf(" ");
            }
            printf("]\n");
            Sleep(100);
        }
    }
    else{
        printf("\nSem carros aguardano no sentido Campos->Guarus\n");
        system("pause");
    }
    if (!qisEmpty(guarus_campos)){
        for (int i = 0; i < 7; i++){
            placa_guarus[i] =dequeue(guarus_campos);
        }
        placa_campos[8] = '\0';
        for(int i = 0; i < 49; i++){
            system("cls");
            printf("\nCarro %s atravessando sentido Guarus->Campos\n", placa_guarus);
            printf("[");
            for(int j = 0; j < i; j++) {
                printf("=");
            }
            for(int h = 48;h > i; h--) {
                printf(" ");
            }
            printf("]\n");
            Sleep(100);
        }
    }
    else{
        printf("\nSem carros aguardano no sentido Guarus->Campos\n\n");
        system("pause");
    }

    return;
}

int main(){
    system("cls");
    int s;
    struct sfila campos_guarus;
    struct sfila guarus_campos;

    qinit(&campos_guarus);
    qinit(&guarus_campos);

    while(s != 0){
        system("cls");
        printf("------------Menu------------\n1 - Cadastrar Campos->Guarus\n2 - Cadastrar Guarus->Campos\n3 - Liberar Travessia\n4 - Sair\n\n");
        scanf(" %d",&s);
        switch(s){
            case 0:

            case 1:
                cadastrar(&campos_guarus, &guarus_campos, s);
                break;
            case 2:
                cadastrar(&campos_guarus, &guarus_campos, s);
                break;
            case 3:
                liberar(&campos_guarus, &guarus_campos);
                break;
            case 4:
                return 0;
                break;
        }
    }
    system("pause");
}