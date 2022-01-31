//Uma solução em C usando backtracking para o problema das 8 rainhas

#include <stdio.h>

int Atacam(int board[8][8],int j,int linha){

    //printf("\ntestando para 1 em [%d][%d]",linha,j);
    int g;
    for(g = 0; g<8; g++){
        if(board[g][j] == 1){
            return 1;
        }
    }
    for(g = 0; g<8; g++){
        if(board[linha][g] == 1){
            return 1;
        }
    }
  
    //a ideia aqui é usar equações de reta para verificar as duas diagonais do tabuleiro
    int x=0;
    int y;
    int a; //i = j + a; i = - j + a
    a = linha - j;
    for(x = 0; x<8; x++){
        y = x + a;
        if (y < 0 || y>8){
            continue;
        }
        if(board[y][x] == 1){
            return 1;
        }
    }

    x = 0;
    a; //y = x + a; y = - x + a
    a = linha + j;
    for(x = 0; x<8; x++){
        y = -x + a;
        if (y < 0 || y>8){
            continue;
        }
        if(board[y][x] == 1){
            return 1;
        }
    }
    return (0);
}
//aqui imprimimos a solução
//a solução é dada com 8 números, onde a posição do número representa a linha e o valor a coluna
//se a solução for 0 6 4 7 1 3 5 2, o primeiro número é 0, então a primeira rainha encontra-se na linha 0, coluna 0, a segunda na linha 1, coluna 6, e assim por diante.
int PrintBoard(int solucao[8]){
    //esse printf para mostrar o resultado poderia ter sido feito de forma iterada.
    //entretanto, o sistema de correção não considerava se feito de outra forma.
    printf("%d %d %d %d %d %d %d %d\n", solucao[0], solucao[1], solucao[2], solucao[3], solucao[4], solucao[5], solucao[6], solucao[7]);
    return(0);
}

int Recursive(int board[8][8], int linha,int solucao[8]){
    int j = 0;
    //printf("%d", linha);

    for (j = 0; j < 8; j++)
    {
        //PrintBoard(solucao);
        if(Atacam(board, j, linha) == 0){
            board[linha][j] = 1;
            solucao[linha] = j;

            //printf("\nadicionado 1 em [%d][%d]",linha,j);
            if(linha+1 == 8){
                //printf("\n");
                PrintBoard(solucao);
                board[linha][j] = 0;
                solucao[linha] = 0;
                //printf("\n");
                break;
            }
            Recursive(board, linha + 1, solucao);
            board[linha][j] = 0;
            solucao[linha] = 0;
        }
        else if(j == 7){
            return(0);
        }
    }
}

int main(void){
    int solucao[8] = {0};
    int board[8][8] = {0};
    
    Recursive(board, 0, solucao);
    return 0;
}
