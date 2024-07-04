#include <stdio.h>
int main(void){
    int inputSegundos; float horas; float minutos; float seg;
    scanf("%d", &inputSegundos);
    float f_input = inputSegundos;

    horas = (int)(inputSegundos/(60*60));
    minutos = (int)(((f_input/(60*60)) - horas)*60);
    seg = f_input - (minutos*60 + horas*3600);

    int int_horas = (int)horas;
    int int_minutos = (int)minutos;
    int int_seg = (int)seg;

    printf("%02d:%02d:%02d",int_horas,int_minutos,int_seg);
    return(0);
}
