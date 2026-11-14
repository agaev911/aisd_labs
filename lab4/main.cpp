#include "pyramid.h"
#include <chrono>
#include <ctime>

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
    Outputmas(arr, n);

    cout << "До сортировки: " << (isSorted(arr, n) ? "отсортирован" : "не отсортирован") << "\n";

    auto start = chrono::high_resolution_clock::now();
    pyramidSort(arr, n);
    auto end = chrono::high_resolution_clock::now();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nОтсортированный: ";
    Outputmas(arr, n);

    cout << "После сортировки: " << (isSorted(arr, n) ? "отсортирован" : "НЕ ОТСОРТИРОВАН") << "\n";

    cout << "затраченное время: " << chrono::duration<double, milli>(end - start).count();

    delete[] arr;
    return 0;
}
