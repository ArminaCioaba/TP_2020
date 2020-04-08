/*
	Pentru afisarea verticala a unui numar �ntreg (c�te o cifra pe r�nd) se poate folosi o stiva �n care se vor depune resturile 
�mpartirilor repetate la 10.
	Scrieti o functie av�nd ca argument un numar �ntreg, care �l afiseaza vertical, folosind o stiva.
*/
#include <stdio.h>
#include <stdlib.h>
int stiva[50], varf = -1;
void push(int x)
{
	stiva[++varf] = x;
}
int pop()
{
	return stiva[varf--];
}
void afiseaza_numar(int numar)
{
	while (numar) {
		push(numar % 10);
		numar /= 10;
	}
	printf("Numarul afisat vertical cu ajutorul stivei : \n");
	while (varf > -1) {
		printf("%d\n", pop());
	}
}
int main()
{
	int numar;
	printf("Introduceti numarul : ");
	scanf("%d", &numar);
	afiseaza_numar(numar);
	system("pause");
	return 0;
}