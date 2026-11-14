#pragma once

//#include <cstdio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <iostream>
#define UI unsigned int

using namespace std;


void Swap(int* a, int* b) {
	int tmp = *a; *a = *b; *b = tmp;
}

void RandiAnymas(int* a, int n, int lf, int rt) {
	srand(time(0));
	for (int i = 0; i < n; i++)
		a[i] = rand() % (rt - lf + 1) + lf;

}

void RandAnymas(int* a, int n) {
	int rt = 30, lf = 1;
	srand(time(0));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (rt - lf + 1) + lf;
		lf = a[i] + 1; rt += 10;
	}
}

void Outputmas(int* a, int n) {
	cout << "Your array: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	//puts("\n");
}

int Definebit8(UI value, int k)
{
	UI mask = 3; UI itog;  // mask = 11
	mask <<= k - 2;
	itog = (value & mask);
	itog >>= k - 2;
	if ((itog == 3) || (itog == 0)) return 0;
	else return 1;
}

UI Input2BV(char s[], int n) {
	UI x = 0, mask = 1; int i;
	for (i = 0; i < n; i++) {
		x <<= 1;
		if (s[i] == '1') x++;
	}
	return x;
}

void OutputBV(UI x, int n) {
	UI mask = 1; int i;
	mask <<= n - 1;
	for (i = 0; i < n; i++, mask >>= 1)
		if (x & mask) printf("1");
		else printf("0");
}

UI Invert(UI x, int k)
{
	UI mask = 1;
	mask <<= k;
	x ^= mask;
	return x;
}

UI Invertk(UI x, int k) {
	UI mask = 1;
	for (int i = 0; i < k; i++, mask <<= 1)
		x ^= mask;
	return x;
}

UI Invert8(UI x, int k)
{
	UI mask = 3; //mask = 11
	mask <<= k - 2;
	x ^= mask;
	return x;
}

void InputBM(UI* bm, int m, int n) {
	int i; char s[33];
	for (i = 0; i < m; i++) {
		gets_s(s);
		bm[i] = Input2BV(s, n);
	}
}

void OutputBM(UI* bm, int m, int n) {
	int i;
	for (i = 0; i < m; i++) {
		OutputBV(bm[i], n);
		printf("\n");
	}
}

void Open_error(errno_t a) {
	if (a) {
		perror("error opening file in Open_error");
		(void)getchar(); // явное приведение к void
		exit(-1);
	}
}

void Open_error6(FILE* a) {  //файлы №6
	if (a == NULL) {
		perror("error opening file in Open_error6");
		getchar();
		exit(-1);
	}
}

void CreateFile(const char* name, int n, int lf, int rt) {
	int x; FILE* f;
	errno_t f_err = fopen_s(&f, name, "w");
	Open_error(f_err);
	srand(time(0));
	for (int i = 0; i < n; i++) {
		x = rand() % (rt - lf + 1) + lf;
		fprintf(f, "%d ", x);
	}
	fclose(f);
}

void CreateFile6(const char* name, int n, int lf, int rt) { // Файлы №6
	int x; FILE* f;
	fopen_s(&f, name, "w");
	Open_error6(f);
	srand(time(0));
	for (int i = 0; i < n; i++) {
		x = rand() % (rt - lf + 1) + lf;
		lf = x + 1;
		fprintf(f, "%d ", x);
		rt += 50;
	}
	fclose(f);
}

void CreateFile(const char* name, int n, int lf, int rt)
//name – имя создаваемого файла;
//n – количество чисел; lf, rt – левая, правая границы диапазона.
{
	FILE* f; // объявление файловой переменной
	int x;
	f = fopen(name, "w"); // открыть файл в режиме - записи
	if (f == NULL) { perror("error opening file in CreateFile"); exit(-1); }
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		x = rand() % (rt - lf + 1) + lf; // получить случайное число
		fprintf(f, "%d ", x);  // записать x в файл
	}
	fclose(f); // закпыть файл
}

void PrintFile(const char* name) {
	FILE* f; int x;
	errno_t f_err = fopen_s(&f, name, "r");
	Open_error(f_err);
	while (fscanf_s(f, "%d", &x) != EOF)
		printf("%d ", x);
	fclose(f);
	puts("\n");
}

void PrintFile6(const char* name) {//файлы №6
	FILE* f; int x;
	fopen_s(&f, name, "r");
	Open_error6(f);
	while (fscanf_s(f, "%d", &x) != EOF)
		printf("%d ", x);
	fclose(f);
	puts("\n");
}

void Razbienie(FILE** G) {
	_fcloseall();
	int n, x1, x2; errno_t f_err;
	f_err = fopen_s(&G[2], "filex.txt", "r"); Open_error(f_err);
	f_err = fopen_s(&G[0], "file1.txt", "w"); Open_error(f_err);
	f_err = fopen_s(&G[1], "file2.txt", "w"); Open_error(f_err);
	fscanf_s(G[2], "%d", &x1);
	n = 0;
	while (!feof(G[2])) {
		fprintf(G[n], "%d ", x1);
		fscanf_s(G[2], "%d", &x2);
		while ((!feof(G[2])) && (x1 <= x2)) {
			x1 = x2;
			fprintf(G[n], "%d ", x1);
			fscanf_s(G[2], "%d", &x2);
		}
		x1 = x2;
		n = 1 - n;
	}
	_fcloseall();
}

void Sliyanie(FILE** G) {
	_fcloseall();
	int n, x[2], y[2]; errno_t f_err;
	f_err = fopen_s(&G[2], "filex.txt", "w"); Open_error(f_err);
	f_err = fopen_s(&G[0], "file1.txt", "r"); Open_error(f_err);
	f_err = fopen_s(&G[1], "file2.txt", "r"); Open_error(f_err);
	fscanf_s(G[0], "%d", &x[0]);
	fscanf_s(G[1], "%d", &x[1]);
	while ((!feof(G[0])) && (!feof(G[1]))) {
		if (x[0] < x[1])
			n = 0;
		else
			n = 1;
		fprintf(G[2], "%d ", x[n]);
		fscanf_s(G[n], "%d", &y[n]);
		if ((!feof(G[n])) && (x[n] <= y[n]))
			x[n] = y[n];
		else {
			fprintf(G[2], "%d ", x[1 - n]);
			fscanf_s(G[1 - n], "%d", &y[1 - n]);
			while ((!feof(G[1 - n])) && x[1 - n] <= y[1 - n]) {
				x[1 - n] = y[1 - n];
				fprintf(G[2], "%d ", x[1 - n]);
				fscanf_s(G[1 - n], "%d", &y[1 - n]);
			}
			x[0] = y[0]; x[1] = y[1];
		}
	}

	while (!feof(G[0])) {
		fprintf(G[2], "%d ", x[0]);
		fscanf_s(G[0], "%d", &y[0]);
		x[0] = y[0];
	}

	while (!feof(G[1])) {
		fprintf(G[2], "%d ", x[1]);
		fscanf_s(G[1], "%d", &y[1]);
		x[1] = y[1];
	}
	_fcloseall();
}

void BPoisk(int* mas, int a) {
	int L = 0, R = a - 1, m, n;
	printf("Poisk chisla: "); scanf_s("%d", &n);
	m = (L + R) / 2;
	while (L <= R) {
		if (n > mas[m])
			L = m + 1;
		else
			R = m - 1;
		m = (L + R) / 2;
	}
	if (mas[m] == n) {
		printf("Chislo %d est v massive pod elementom %d", mas[m], m);
	}
	else
		printf("Chisla %d v massive net", n);
}

int SearchBM(char s[], char p[], int m, int n, int TAB[]) {
	int i, j, k;
	i = m - 1;
	j = m - 1;
	while (i < n) {
		k = i;
		j = m - 1;
		while (j >= 0) {
			if (s[k] == p[j]) {
				k--;
				j--;
			}
			else {
				i += TAB[s[k]];
				break;
			}
		}
		if (j < 0)
			return k + 1;
	}
	return 0;
}

void Puzir(int* a, int n) {

	for (int k = n - 1; k > 0; k--)
		for (int i = 0; i < k; i++)
			if (a[i] > a[i + 1])
				Swap(&a[i], &a[i + 1]);
}

void PuzirUL(int* a, int n) {
	int LastSwap = 0;
	int k = n - 1;
	while (k > 0) {
		for (int i = 0; i < k; i++) {
			if (a[i] > a[i + 1])
				Swap(&a[i], &a[i + 1]);
			LastSwap = i;
		}
		k = LastSwap;
	}
}

void Sheik(int* mas, int raz) {
	int left, right;
	for (left = 0, right = raz - 1; left < right; left++) {
		for (int i = left; i < right; i++) {
			if (mas[i] > mas[i + 1])
				Swap(&mas[i], &mas[i + 1]);
		}
		right--;
		for (int j = right; j > left; j--) {
			if (mas[j] < mas[j - 1])
				Swap(&mas[j], &mas[j - 1]);
		}
	}
}

void SheikUL(int* mas, int raz) {
	int left = 0, right = raz - 1, LastSwap = 0;
	while (left < right) {
		for (int i = left; i < right; i++) {
			if (mas[i] > mas[i + 1]) {
				Swap(&mas[i], &mas[i + 1]);
				LastSwap = i;
			}
		}
		right = LastSwap;

		for (int j = right; j > left; j--) {
			if (mas[j] < mas[j - 1]) {
				Swap(&mas[j], &mas[j - 1]);
				LastSwap = j;
			}
		}
		left = LastSwap;
	}
}

int Prioritet(char s) // Приоритет действий
{
	switch (s)
	{
	case '(': return 0;
	case ')': return 1;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	}
}

bool Digit(char ch) // Проверка что это число
{
	if ('0' <= ch && ch <= '9') return true;
	return false;
}

bool bukva(char ch) { // Проверка что это буква 
	if (ch >= 'a' && ch <= 'z')
		return true;
	return false;
}

void Randmatr(int** matr, int strok, int stolb) {
	srand(time(0));
	for (int i = 0; i < strok; i++) {
		for (int j = 0; j < stolb; j++)
			if (i == j)
				matr[i][j] = 0;
			else
				matr[i][j] = rand() % 15 + 1;
	}
}

void Outputmatr(int** matr, int strok, int stolb) {
	cout << "Matrix:\n";
	for (int i = 0; i < strok; i++) {
		for (int j = 0; j < stolb; j++)
			cout << matr[i][j] << "\t";
		cout << "\n";
	}
}


void Peres(int* arr, int size, int k) {
	arr[0] = k;
	arr[size] = k;
	for (int i = 1, t = 1; i < size; i++, t++) {
		if (i == k)
			t++;
		arr[i] = t;
	}
}

int PermutationSum(int** Matr, int* P, int cities) { // Подсчет длины перестановки	
	int total = 0;
	for (int i = 0; i < cities; i++) {
		total += Matr[P[i] - 1][P[i + 1] - 1];
	}
	return total;
}

void OutputPeres(int* P, int cities) {
	for (int i = 0; i < cities; i++)
		cout << P[i] << " ";
	cout << P[0];
}

void Inversion(int* P, int cities, int imax) {
	for (int j = cities - 1, i = imax + 1; i < j; i++, j--) {
		int flag = P[i];
		P[i] = P[j];
		P[j] = flag;
	}
}

bool Permutation(int* P, int cities) {
	int imax = -1, jmax = -1;

	for (int i = 1; i < cities - 1; i++) { // Находим максимальное i 
		if (P[i] < P[i + 1])
			imax = i;
	}
	if (imax == -1)
		return 0;

	for (int j = imax + 1; j < cities; j++) {   // Находим максимальное j 
		if (P[imax] < P[j])
			jmax = j;
	}

	int pris = P[imax];             // Меняем p[imax] & p[jmax] местами
	P[imax] = P[jmax];
	P[jmax] = pris;
	Inversion(P, cities, imax);
	OutputPeres(P, cities);
}


int Perest(int* data, int n) {
	data[0] = 1;
	int  count = 1;
	for (int i = 1; i < n / 2; i++)
	{
		count++;
		if (i % 2 == 0) {
			data[i] = 9 * (pow(2, i)) - 9 * (pow(2, i / 2)) + 1;
		}
		else {
			data[i] = 8 * (pow(2, i)) - 6 * (pow(2, (i + 1) / 2)) + 1;
		}
		if (3 * data[i] > n)
			break;
	}
	return count;
}

void ShellSort(int* mas, int n, int step) {
	for (int i = 0; i < n - step; i++)
	{
		int j = i;
		while (j >= 0 && mas[j] > mas[j + step])
		{
			int tmp = mas[j];
			mas[j] = mas[j + step];
			mas[j + step] = tmp;
			j--;
		}
	}
}

int whatbit(int n, int element)
{
	int mask = 1;
	mask <<= n;
	if (mask & element)
		return 1;
	else
		return 0;
}

int maxbit(int* array, int size) //старший разряд числа
{
	int maxel = array[0];
	for (int i = 0; i < size; i++)
		maxel = max(array[i], maxel);
	int count = 0;
	while (maxel > 0)
	{
		count++;
		maxel >>= 1;
	}
	return count;
}

void bitsort(int* array, int first, int last, int bit)
{
	int i = first, j = last, tmp;

	while (i <= j) {
		while ((whatbit(bit, array[i]) == 0) && (i <= j))
			++i;
		while ((whatbit(bit, array[j]) == 1) && (i <= j))
			--j;
		if (i <= j) {
			if (i < j) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			i++;
			j--;
		}
	}

	if (i < last && bit >= 0) bitsort(array, i, last, bit - 1);
	if (first < j && bit >= 0) bitsort(array, first, j, bit - 1);
}