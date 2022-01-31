/*Você conhece a definição da sequência de Fibonacci. Hoje vamos modificar um pouco essa definição. Vamos definir uma função semelhante a de Fibonacci da seguinte maneira.

Fi[0] = 1;
Fi[1] = 1;
Fi[n] = Fi[Fi[n - 1] % n] + Fi[Fi[n-2] % n];

É claro que essa definição não faria muito sentido se tirássemos as ocorrências da expressão "% n" , porque os índices a = Fi[n-1] e b = Fi[n-1] provavelmente seriam maiores de que n e, portanto, Fi[a] e Fi[b] não estariam ainda definidos no momento em que estivéssemos definindo Fi[n]. Por isso, colocando "% n", temos a certeza de que Fi[n-1] % n e também Fi[n-2] % n são ambos índices no intervalo 0 ... (n - 1).

Neste exercício programa, você deverá implementar um programa para calcular Fi, a sequência "Fibonacci Iterada".*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *fi;
    int n;
    int maxn = 1;
    int i;
    int *f = (int *) calloc(2,sizeof(int));
    fi = f;
    *(f+0) = 1;
    *(f+1) = 1;

    while (scanf("%8d", &n) == 1){
        if(n > 50000000){
            return(0);
        }
        if(n > maxn){
            fi = realloc(f, (n+1)*sizeof(int));
            if(fi == NULL){
                printf("Memory fault at trying to allocate %d int's", n);
                return(0);
            }
            f = fi;
            for (i = maxn+1; i <= n; i++){
                *(f+i) = *(f + (*(f+i-1) % i)) + *(f + (*(f+i-2) % i));
            }
            maxn = n;
        }
        printf("%d\n", *(f+n));
    }
    free(f);
    free(fi);
    return 0;
}
