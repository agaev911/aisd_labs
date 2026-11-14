#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void RandiAnymas(int* a, int n, int lf, int rt) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = rand() % (rt - lf + 1) + lf;

}

void Outputmas(int* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << "\n";
}

bool isSorted(int* a, int n)
{
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

void QuickSort(int* array, int left, int right) {
    if (left < right) {
        int i = left;
        int j = right;
        int x = array[(i + j) / 2];
        while (i <= j) {
            while (array[i] < x)
                i++;
            while (array[j] > x)
                j--;
            if (i <= j) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                i++;
                j--;
            }
        }
        QuickSort(array, left, j);
        QuickSort(array, i, right);

    }
    return;

}