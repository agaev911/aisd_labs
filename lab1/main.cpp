#include "salesman.h"

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));

    int n;
    cout << "Введите количество городов: ";
    cin >> n;

    // Матрица
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    Randmatr(matrix, n, 1, 100);
    Outputmatr(matrix, n);

    // Начальный город
    int k;
    do {
        cout << "\nВведите начальный город (1-" << n << "): ";
        cin >> k;
    } while (k < 1 || k > n);

    // Точное решение
    int* bestTour = new int[n + 1];
    int exactCost = Poln(matrix, n, k, bestTour);

    cout << "\n=== ТОЧНОЕ РЕШЕНИЕ (ПЕРЕБОР) ===\n";
    cout << "Лучший тур: ";
    OutputPeres(bestTour, n);
    cout << "Стоимость: " << exactCost << "\n";

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] bestTour;

    return 0;
}