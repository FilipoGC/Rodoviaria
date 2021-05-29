#include <stdlib.h>
#include <stdio.h>

/*

9:00 = chegada: 1  partida: 0  No box: 1
9:10 = chegada: 0  partida: 1  No box: 0
9:40 = chegada: 1  partida: 0  No box: 1 
9:50 = chegada: 1  partida: 0  No box: 2 
11:00 = chegada: 1  partida: 0  No box: 3
11:20 = chegada: 0  partida: 1  No box: 2
11:30 = chegada: 0  partida: 1  No box: 1
12:00 = chegada: 0  partida: 1  No box: 0
15:00 = chegada: 1  partida: 0  No box: 1
18:00 = chegada: 1  partida: 0  No box: 2
19:00 = chegada: 0  partida: 1  No box: 1
20:00 = chegada: 0  partida: 1  No box: 0



{18:00, 9:40 , 9:00, , 9:50 , 15:00 , 11:00 } {20:00, 12:00, 9:10, 11:20, 19:00, 11:30 }
	1	  1     1       1       1       1        2      2      2       2      2      2

*/

void printFloat(float *v, int tam){

	int i;
	for(i = 0; i < tam; i++) printf("%.2f ", v[i]);
	printf("\n");
}

void print(int *v, int tam){

	int i;
	for(i = 0; i < tam; i++) printf("%d ", v[i]);
	printf("\n");
}


void swapFloat(float *p1, float *p2){

	float aux = *p1;
	*p1 = *p2;
	*p2 = aux;

}


void swap(int *p1, int *p2){

	int aux = *p1;
	*p1 = *p2;
	*p2 = aux;

}

void bubbleSort(int tam, float *horarios, int *chepar){
	printf("Execucao do Bubble Sort\n");
	int i;
	int j;
	for(j = 1; j <= tam; j++) {
		int flag = 1;
		for(i = 0; i < tam-j; i++) {
			if( horarios[i] > horarios[i+1]) {
				swapFloat(&horarios[i], &horarios[i+1]);
				swap(&chepar[i], &chepar[i+1]);
				flag = 2;
			}
		}
		if(flag == 1) break;
	}
}	

void main () {
	int i;
	int atual = 0;
	int max = 0;
	int tam = 12;
	float horarios [12] = {18.0, 9.4, 9.0, 9.5, 15.0, 11.0, 20.0, 12.0, 9.1, 11.2, 19.0, 11.3};
	int chegadaOUpartida [12] = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
	
	bubbleSort(tam, horarios, chegadaOUpartida);
	
	printFloat(horarios, 12);
	print(chegadaOUpartida, 12);
	
	for(i = 0; i < tam; i++) {
		if (chegadaOUpartida[i] == 1) atual++;
		else atual--;
		if (atual > max) max = atual; 
	}
	printf("O numero de boxes necessarios, para que nenhum onibus fique esperando eh: %d\n", max);
	
}
