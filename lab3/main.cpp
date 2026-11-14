#include "shell.h"

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n];
    RandiAnymas(arr, n, 1, 100);

    cout << "\nИсходный массив: ";
    printArray(arr, n);

    //формирование шагов
    int* h = new int[n];
    int t = 0;

    //заполняем шаги
    for (int step = n / 2; step > 0; step /= 2)
        h[t++] = step;

    // Выводим шаги
    cout << "Шаги: ";
    for (int i = 0; i < t; i++)
        cout << h[i] << " ";
    cout << "\n";

    shellSort(arr, n, h, t);

    cout << "\nОтсортированный: ";
    printArray(arr, n);

    cout << "Проверка: " << (isSorted(arr, n) ? "OK" : "FAIL") << "\n";

    delete[] arr;
    delete[] h;
    return 0;
}