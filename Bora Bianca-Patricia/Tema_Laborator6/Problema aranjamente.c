#include<stdio.h>
#include<stdlib.h>

int i, k, n, m, v[100], sol = 0; cnt = 0;
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
	for (i = 1; i < k; i++) // verific� dac� elementul din
		if (v[i] == v[k]) return 0; // v�rf este diferit de
		// elemente precedente din stiv�
	return 1;
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
		if (k <= m) // nu face sens dep�irea nivelului n �n stiv�
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
	n = 4; m = 3;
	Back();
	return 0;
	system("pause");
	return 0;

}