#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "fila.h"

void cadastrar(struct sfila campos_guarus,struct sfila guarus_campos, int s){
    char placa[7];
    printf("Informe a placa do veiculo para cadastra-lo na travessia: ");
    scanf("%s",placa);
    switch (s){
        case 0:
            for (int i = 0; i <= 6; i++){
                enqueue(&campos_guarus,placa[i]);
            }
            printf("\nO veiculo %s foi cadastrado no sentido Campos->Guarus\n",placa);
            return;
    }
}

void liberar(struct sfila campos_guarus,struct sfila guarus_campos){
    if (!qisEmpty(&campos_guarus) && !qisEmpty(&guarus_campos)){
       printf("Sem carros para atravessar");
    }
    if (!qisEmpty(&campos_guarus)){
        for (int i = 0; i < 6; i++){
            dequeue(&campos_guarus);
        }
    }
    if (!qisEmpty(&guarus_campos)){
        for (int i = 0; i < 6; i++){
            dequeue(&guarus_campos);
        }
   }
    for(int i = 0; i < 49; i++){
        system("cls");
        printf("\n     Carro atravessando sentido Campos->Guarus\n");
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

int main(){

    struct sfila campos_guarus;
    struct sfila guarus_campos;

    qinit(&campos_guarus);
    qinit(&guarus_campos);
    int s;
    scanf(" %i",&s);
    cadastrar(campos_guarus, guarus_campos, s);
    liberar(campos_guarus, guarus_campos);
    system("pause");
}