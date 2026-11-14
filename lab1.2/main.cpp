#include "salesman.h"
#include <iostream>
using namespace std;

bool SearchSity(int* peres, int n, int cities) {
	for (int i = 0; i < cities; i++)
		if (peres[i] == n)
			return 1;
	return 0;
}

int main() {
	int repi = 1;
	while (repi == 1) {
		int** matrix, ** matrixcopy, Cities, k;

		cout << "How many cities: ";
		cin >> Cities;
		matrix = new int* [Cities];
		for (int i = 0; i < Cities; i++)
			matrix[i] = new int[Cities];

		matrixcopy = new int* [Cities];
		for (int i = 0; i < Cities; i++)
			matrixcopy[i] = new int[Cities];

		Randmatr(matrix, Cities, Cities);
		Randmatr(matrixcopy, Cities, Cities);
		Outputmatr(matrix, Cities, Cities);

		cout << endl << "Enter city number: ";
		cin >> k;

		if (k > Cities) {
			cout << "\nWe have only " << Cities << " cities\nEnter city number: ";
			cin >> k;
		}

		int* peres = new int[Cities + 1];
		for (int i = 1; i < Cities; i++)
			peres[i] = 0;
		peres[0] = k;
		peres[Cities] = k;
		int ci = k - 1;
		int summaperes = 0;
		int minij;


		for (int i = 1; i < Cities; i++) {
			int mini = INT_MAX;
			for (int j = 0; j < Cities; j++) {
				bool serch = SearchSity(peres, j + 1, Cities);
				if (serch == true)
					continue;
				if (matrixcopy[ci][j] < mini) {
					mini = matrixcopy[ci][j];
					minij = j;
				}
			}

			summaperes += matrixcopy[ci][minij];
			for (int a = 0; a < Cities; a++) {
				matrix[ci][a] = 0;
				matrix[a][minij] = 0;
			}
			peres[i] = minij + 1;
			ci = minij;

			Outputmatr(matrix, Cities, Cities);
			cout << "\n";
			OutputPeres(peres, i + 1);
			cout << "\n";
		}


		summaperes += matrixcopy[ci][k - 1];
		cout << "\nSumma = " << summaperes;

		cout << "\n";
		OutputPeres(peres, Cities);

		for (int i = 0; i < Cities; i++)
			delete[] matrix[i];
		delete[] matrix;
		delete[] peres;
		cout << "\nRepeat?\n1) Yes\n2) Not\n";
		cin >> repi;

	}
}
