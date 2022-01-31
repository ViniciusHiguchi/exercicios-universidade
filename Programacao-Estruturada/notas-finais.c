/*Neste exercício-programa, sua tarefa é calcular a média e conceito finais de todos os alunos da turma de Programação Estruturada e gerar um relatório.
De acordo com o nosso calendário, teremos 9 tarefas para entrega, portanto 9 notas por aluno. Cada aluno é identificado por seu RA, que (para simplificar)
vamos supor que são números em sequência, começando de 1. Se um aluno não entregar um exercício-programa (EP) a nota desse EP, para aquele aluno, será zero.
Pelas regras do curso, uma atividade será bônus, ou seja não entrará no denominador. Neste curso, a tarefa bônus corresponderá ao EP da quinta semana de aula
(sobre ponteiros). Portanto, a quinta nota de cada aluno será o exercício bônus. Finalmente, também pelas regras do curso e para ajudar os alunos, as duas
menores notas de EPs serão desprezadas e não entrarão no cômputo da média final. Neste EP, não serão consideradas reprovações por faltas (i.e. conceito O).
Se tiver dúvidas sobre o cálculo da média final, ou qualquer outro aspecto, consulte o nosso plano de ensino.*/

/* [Cômputo da média final]
A média final será a média aritmética das notas obtidas nas atividades (EPs) atribuídas ao longo do quadrimestre, desprezando-se as duas menores notas para
o cômputo da média final. O aluno contará também com alguns bônus, em algumas atividades que serão indicados explicitamente pelos professores da disciplina.
*/

#include <stdio.h>

int main(void){
	//1st input n < 130
	//next linhas[n] aluno: [RA 00 01 02 03 04 05 06 07 08 09]
	//
	//output: [RA media.123 Conceito] n-times
	//printf("\n")
	//A numero relativo.1
	//B -----
	//C
	//D
	//F

	double num;
	int i;
	int j;

	double min1 = 100;
	double min2 = 100;
	double total;
	double media;
	char conceitoC;

	double conceito[5] = {0, 0, 0, 0, 0};

	scanf("%lf", &num);
	
	double notas[(int)num][10]; 

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < 10; j++)
		{
			scanf("%lf", &notas[i][j]);
			//printf("nota %lf atribuida\n",notas[i][j]);
		}
	}

	//printf("%d \n",(int)notas[0][0]);
	//printf("%d \n\n",(int)notas[1][0]);

	for (i = 0; i < num; i++)
	{
		//printf("%d ",(int)notas[i][0]);
		for (j = 1; j < 10; j++)
		{
			total += notas[i][j];
			if(notas[i][j] < min1){
				min2 = min1;
				min1 = notas[i][j];
			}
			else if (notas[i][j] < min2){
				min2 = notas[i][j];
			}
		}
		media = ((total - (min1 + min2))/6.0);
		media = ((int)((media)*1000+0.5))/1000.0;
		//printf("min1 %lf min2 %lf\n",min1, min2);
		if(media >= 8.5){
			conceito[0]++;
			conceitoC = 'A';
		}
		if (media >= 7 && media < 8.5){
			conceito[1]++;
			conceitoC = 'B';
		}
		if (media >= 5.5 && media < 7){
			conceito[2]++;
			conceitoC = 'C';
		}
		if (media >= 4.5 && media < 5.5){
			conceito[3]++;
			conceitoC = 'D';
		}
		if (media < 4.5){
			conceito[4]++;
			conceitoC = 'F';
		}
		printf("%d %.3f %c\n",(int)notas[i][0], media, conceitoC);
		min1 = 100; 
		min2 = 100;
		conceitoC = 'N';
		total = 0;
		media = 0;
	}

	printf("\nA %d %.1lf\n",(int)conceito[0], (conceito[0]*100/num));
	printf("B %d %.1lf\n",(int)conceito[1], (conceito[1]*100/num));
	printf("C %d %.1lf\n",(int)conceito[2], (conceito[2]*100/num));
	printf("D %d %.1lf\n",(int)conceito[3], (conceito[3]*100/num));
	printf("F %d %.1lf\n",(int)conceito[4], (conceito[4]*100/num));
	
	return 0;
}
