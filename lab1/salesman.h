#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Randmatr(int** matr, int n, int lf, int rt)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                matr[i][j] = 0;  // нельзя ехать в себя
            else
                matr[i][j] = rand() % (rt - lf + 1) + lf;
        }
    }
}

void Outputmatr(int** matr, int n)
{
    cout << "Матрица стоимостей:\n     ";
    for (int j = 0; j < n; j++) cout << j + 1 << "\t";
    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < n; j++)
            cout << matr[i][j] << "\t";
        cout << "\n";
    }
}

void OutputPeres(int* P, int n)
{
    for (int i = 0; i < n; i++)
        cout << P[i] << " -> ";
    cout << P[0] << endl;
}

int PermutationSum(int** Matr, int* P, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += Matr[P[i] - 1][P[i + 1] - 1];
    return total;
}

void Peres(int* arr, int n, int k)
{
    arr[0] = k;
    arr[n] = k;

    int t = 1;
    for (int i = 1; i < n; i++)
    {
        if (t == k) t++;
        arr[i] = t++;
    }
}

void Inversion(int* P, int n, int imax)
{
    for (int j = n - 1, i = imax + 1; i < j; i++, j--)
    {
        int tmp = P[i];
        P[i] = P[j];
        P[j] = tmp;
    }
}

bool Permutation(int* P, int n) //дейкстра
{
    int imax = -1, jmax = -1;

    for (int i = 1; i < n - 1; i++)
    {
        if (P[i] < P[i + 1])
            imax = i;
    }

    if (imax == -1)
        return false;

    for (int j = imax + 1; j < n; j++)
    {
        if (P[imax] < P[j])
            jmax = j;
    }

    int tmp = P[imax];
    P[imax] = P[jmax];
    P[jmax] = tmp;

    Inversion(P, n, imax);

    return true;
}


int Poln(int** costMatrix, int n, int startCity, int* bestTour)
{
    int* perest = new int[n + 1];

    Peres(perest, n, startCity);

    int minCost = PermutationSum(costMatrix, perest, n);

    for (int i = 0; i < n; i++)
        bestTour[i] = perest[i];
    bestTour[n] = startCity;

    while (Permutation(perest, n))
    {
        int cost = PermutationSum(costMatrix, perest, n);

        if (cost < minCost)
        {
            minCost = cost;
            for (int i = 0; i < n; i++)
                bestTour[i] = perest[i];
            bestTour[n] = startCity;
        }
    }

    delete[] perest;
    return minCost;
}