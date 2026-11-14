#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
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

void Swap(int* a, int* b) {
	int tmp = *a; *a = *b; *b = tmp;
}

bool isSorted(int* a, int n)
{
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

void Sift2(int* a, int n, int i)
{
    int j = 2 * i + 1; 
    int x = a[i];
    int f = 1;

    while (j < n && f)
    {
        if (j + 1 < n && a[j + 1] > a[j])
            ++j;

        if (a[j] > x)
        {
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            f = 0;
        }
    }

    a[i] = x;
}

void buildPyramid(int* a, int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
        Sift2(a, n, i);
}

void pyramidSort(int* a, int n)
{
    buildPyramid(a, n);

    for (int i = n - 1; i >= 1; --i)
    {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        Sift2(a, i, 0);
    }
}