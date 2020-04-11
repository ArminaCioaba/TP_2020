#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
int ataca(int linie, int memorie[])
//aceasta func�ie testeaz� daca regina de pe linie este atacata de reginele pozi�ionate anterior.Este de fapt func�ia de Validare//
{
	int i;
	//luam pe r�nd toate damele pozi�ionate anterior//
	for (i = 0; i < linie; i++)
		//verificam daca cele 2 dame sunt pe aceea�i coloana sau pe diagonal�//
		if ((memorie[linie] == memorie[i]) ||
			(abs(memorie[i] - memorie[linie]) == linie - i))
			// se ataca, deci nu sunt corect pozi�ionate.//
			return 1;
		else
	       return 0; //daca am ajuns aici, �nseamn� c� nu se atac�//
}
//c�ile de afi�are sunt infinite//
void afiseaza(int dim, int memorie[])
{
	int l, c;
	for (l = 0; l <= dim; l++)
		printf("_");
	for (l = 0; l < dim; l++)
	{
		printf("\n|");
		for (c = 0; c < dim; c++)
			if (memorie[l] == c)
				printf("%c", 6);
			else
				if ((l + c) & 1)
					printf(" ");
				else
					printf("%c", 219);
		printf("|");
	}
	printf("\n");
	for (l = 0; l <= dim; l++)
		printf("-");
	printf("\n");
	printf("o tasta!\n");
	getch();
}
void regine(int dim, int linie, int memorie[])
// aici este func�ia care face efectiv backtracking-ul (suntem la linia(nivelul) linie.//
// dim ne spune c�t de mare-i tabla//
// memorie tine minte damele deja pozi�ionate. Ea este stiva.//
{
	if (linie == dim)// daca am terminat//
		afiseaza(dim, memorie);//afi��m//
	else //altfel avem de lucru//
		for (memorie[linie] = 0; memorie[linie] < dim; memorie[linie]++)
			//�ncercam toate coloanele de la st�nga la dreapta//
			if (!ataca(linie, memorie))
				//daca e o pozi�ie valida trecem la nivelul urm�tor//
				regine(dim, linie + 1, memorie);
	//c�nd ne �ntoarcem din apelul recursiv �nseamn� c� am revenit la acest nivel �i �ncerc�m urm�toarea coloana//
}

void main()
{
	int n, memorie[100];
	printf("dimensiunea tablei de joc");
	scanf("%d", &n);
	regine(n, 0, memorie);// prima linie are num�rul zero//
}