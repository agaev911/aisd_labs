#pragma once
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

bool Permutation(int* P, int cities)
{
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


