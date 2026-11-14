#include "pyramid.h"

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

    pyramidSort(arr, n);

    cout << "\nОтсортированный: ";
    Outputmas(arr, n);

    cout << "После сортировки: " << (isSorted(arr, n) ? "отсортирован" : "НЕ ОТСОРТИРОВАН") << "\n";

    delete[] arr;
    return 0;
}