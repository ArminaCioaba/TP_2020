
#include<stdio.h>
#include<stdlib.h>

int i, k, n, v[100], sol = 0; cnt = 0, m;
char isS, isV = 0;
void Init(int k) { // k � v�rful stivei
	v[k] = 0; //ini�ializeaz�/reseteaz�, valoarea din
	// v�rful stivei
}
int Succesor(int k) {
	if (v[k] < n) { // se poate cre�te valoarea din v�rf
		v[k]++; // se incrementeaz� valoarea din v�rf
		return 1; // func�ia a avut success
	}
	else // nu se poate cre�te valoarea din v�rf
		return 0;
}

int Valid(int k) {
	int oglindit = 0;
	int copie, cifra;
	for (i = 1; i <= m; i++) {

		copie = v[i];
		while (copie != 0)
		{
			cifra = copie % 10;
			copie = copie / 10;
			oglindit = oglindit * 10 + cifra;
		}

		if (v[i] == oglindit)

			return 1;
	}
	
	return 0;
}
int Solution(k) {
	return (k == m);
}
void Print() {
	printf("%d : ", ++sol);
	for (i = 1; i <= m; i++)
		printf("%d ", v[i]);
	printf("\n");
}
void Back() {
	k = 1; Init(k);
	while (k > 0) { // c�t timp stiva nu e vid�
		isS = 0; isV = 0;
		if (k <= m) // nu are sens dep�irea nivelului m �n stiv�
			do { // repet� c�t timp...
				isS = Succesor(k);
				if (isS) isV = Valid(k);
			} while (isS && !isV); // ...exist� succesor dar nu este valid
			if (isS) //este succesor si este valid
				if (Solution(k)) // verific� candidatul la solu�ie
					Print(); // afi�eaz� solu�ia
				else { // dac� nu este solu�ie
					k++;
					Init(k); // cre�te v�rful stivei �i ini�ializeaz�
				}
			else // nu exist� succesor pt. valoarea curent� din stiv�
				k--; // -> se coboar� o pozi�ie �n stiv�
	}
}
int main() {
	int n = 44;
	Back();
	return 0;
	system("pause");
	return 0;

}