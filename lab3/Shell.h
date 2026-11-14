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

void printArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

bool isSorted(int* a, int n)
{
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

void insertSubsequence(int* a, int n, int b, int s)
{
    // j = b + s
    for (int j = b + s; j < n; j += s)
    {
        int x = a[j];
        int k = j - s;

        while (k >= 0 && a[k] > x)
        {
            a[k + s] = a[k];
            k -= s;
        }

        a[k + s] = x;
    }
}

void shellSort(int* a, int n, int* h, int t)
{
    for (int i = 0; i < t; i++)
    {
        int s = h[i];  // текущий шаг

        // Для каждой подпоследовательности
        for (int b = 0; b < s; b++)
        {
            insertSubsequence(a, n, b, s);
        }
    }
}