#include <stdio.h>

#define JOGADOR_X 1
#define JOGADOR_0 2

//código possui um erro se colocar 2/2 ou 2/0 como posição player ganha automáticamente 

int value0(int matriz[][3]){
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            matriz[i][j]=0;
        }
    }
}

int printcamp(int matriz[][3]){

     for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

int verifposicao(int matriz[][3], int posicao[], int alt){

    if (matriz[posicao[0]][posicao[1]] !=0 ){
        return 0;

    }else{
        return 1;
    }
}

int main(){

    int campo[3][3];
    int jogadas = 0;
    int alt=2;
    int win = 0;
    int posicao[2];
   
    

    value0(campo);
    printcamp(campo);

    while ( jogadas<9 && !win )
    {

        if(alt ==2){

            for(int i= 0; i<2; i++){

                printf("escolha a posicao %d player 2: ", i+1);
                scanf("%d", &posicao[i]);

                if(i==1 && !verifposicao(campo,posicao,alt)){
                    printf("ja possui player nessa posicao \n");
                    i=-1;

                }else if (i==1){
                    campo[posicao[0]][posicao[1]] = JOGADOR_0;
                    printf("armazenado \n");
                    
                    int ehIgual = 0;

                    //Verfica se a linha é toda igual
                    for(int j = 0; j < 3; j++){ 
                        if(campo[posicao[0]][j] == JOGADOR_0){
                            ehIgual = 1;
                        }else{
                            ehIgual = 0;
                            break;
                        } 
                    }
    
                    if(ehIgual){
                        win = JOGADOR_0;
                    }

                    ehIgual = 0;
                    
                    //Verifica se a coluna é toda igual
                    for(int j = 0; j < 3; j++){ 
                        if(campo[j][posicao[1]] == JOGADOR_0){
                            ehIgual = 1;
                        }else{
                            ehIgual = 0;
                            break;
                        } 
                    }
                    if(ehIgual){
                        win = JOGADOR_0;
                    }
                    ehIgual = 0;
                    
                    if(posicao[0] == posicao[1] || 2 == posicao[0] + posicao[1]) {
                        // diagonal principal
                        ehIgual = 0;
                        for(int i = 0; i < 3; i++) {
                            if(campo[i][i] == JOGADOR_0) {
                                ehIgual = 1;
                            } else {
                                ehIgual = 0;
                                break;
                            }
                        }
                        if(ehIgual == 1) {
                            win = JOGADOR_0;
                        }
                        // diagonal secundaria
                        for(int i = 0; i < 3; i++) {
                            if(campo[i][2 - i] == JOGADOR_0) {
                                ehIgual = 1;
                            } else {
                                ehIgual = 0;
                                break;
                            }
                        }
                        if(ehIgual == 1) {
                            win = JOGADOR_0;
                        }
                    }

            }
                

            }
            printcamp(campo);
            alt =1;
            jogadas += 1;

        }else if (alt ==1)
        {

            for(int i= 0; i<2; i++){
                
                printf("escolha a posicao %d player 1: ", i+1);
                scanf("%d", &posicao[i]);

                if(i==1 && !verifposicao(campo,posicao,alt)){
                    printf("ja possui player nessa posicao \n");
                    i= -1;

                }else if (i==1)
                {
                    campo[posicao[0]][posicao[1]] = JOGADOR_X;
                    printf("armazenado \n");
                    int ehIgual = 0;

                    for(int j = 0; j < 3; j++){
                        if(campo[posicao[0]][j] == JOGADOR_X){
                            ehIgual = 1;
                        }else{
                            ehIgual = 0;
                            break;
                        } 
                    }
    
                    if(ehIgual){
                        win = JOGADOR_X;
                    }

                    ehIgual = 0;

                    for(int j = 0; j < 3; j++){
                        if(campo[j][posicao[1]] == JOGADOR_X){
                            ehIgual = 1;
                        }else{
                            ehIgual = 0;
                            break;
                        } 
                    }
                    if(ehIgual){
                        win = JOGADOR_X;
                    }
                    ehIgual = 0;

                    if(posicao[0] == posicao[1] || 2 == posicao[0] + posicao[1]) {
                        // diagonal principal
                        ehIgual = 0;
                        for(int i = 0; i < 3; i++) {
                            if(campo[i][i] == JOGADOR_X) {
                                ehIgual = 1;
                            } else {
                                ehIgual = 0;
                                break;
                            }
                        }
                        if(ehIgual == 1) {
                            win = JOGADOR_X;
                        }
                        // diagonal secundaria
                        for(int i = 0; i < 3; i++) {
                            if(campo[i][2 - i] == JOGADOR_X) {
                                ehIgual = 1;
                            } else {
                                ehIgual = 0;
                                break;
                            }
                        }
                        if(ehIgual == 1) {
                            win = JOGADOR_X;
                        }
                    }
              }

            }
            printcamp(campo);
            alt=2;
            jogadas += 1;
        }
        
       
    }
    printf("O PLAYER %d GANHOU!!!!!", win);
}