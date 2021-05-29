#include <stdio.h>
#include <stdlib.h>

void print(float *v, int tam){

	int i;
	for(i = 0; i < tam; i++) printf("%.2f ", v[i]);
	printf("\n");
}

void swap(float *p1, float *p2){

	float aux = *p1;
	*p1 = *p2;
	*p2 = aux;

}

void bubbleSort(int tam, float *v){
	int i;
	int j;
	for(j = 1; j <= tam; j++) {
		for(i = 0; i < tam-j; i++) {
			if( v[i] > v[i+1]) {
				swap(&v[i], &v[i+1]);
			}
		}
	}
}	

void main () {
	int i, j, k, contagem, max;
	float v[12];
	float chegada[6] = {18.00, 9.40 , 9.00, 9.50 , 15.00 , 11.00};
	float saida[6] = {20.00, 12.00, 9.10, 11.20, 19.00, 11.30};
	for (i = 0; i < 6; i++)v[i] = chegada[i];
	for (j = 0; j < 6; j++)v[j+6] = saida[j];
	print(v, 12);
	bubbleSort(12, v);
	print(v, 12);
	for (k = 0; k < 12; k++) {
		if (v[k] == chegada[0] || v[k] == chegada[1] || v[k] == chegada[2] || v[k] == chegada[3] || v[k] == chegada[4] || v[k] == chegada[5]){
			contagem++;
			printf("Quantidade de onibus na rodoviaria: %d\n", contagem);
		}
		else{
			contagem--;
			printf("Quantidade de onibus na rodoviaria: %d\n", contagem);
		}
	if(contagem > max)max = contagem;
}
printf("Numero de boxes necessarios: %d\n", max);
	
}
