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
int whatbit(int n, int element)
{
	int mask = 1;
	mask <<= n;
	if (mask & element)
		return 1;
	else
		return 0;
}

int maxbit(int* array, int size) //старший разряд числа
{
	int maxel = array[0];
	for (int i = 0; i < size; i++)
		maxel = max(array[i], maxel);
	int count = 0;
	while (maxel > 0)
	{
		count++;
		maxel >>= 1;
	}
	return count;
}

void bitsort(int* array, int first, int last, int bit)
{
	if (last <= 1) return;

	int i = first, j = last, tmp;

	while (i <= j) {
		while ((whatbit(bit, array[i]) == 0) && (i <= j))
			++i;
		while ((whatbit(bit, array[j]) == 1) && (i <= j))
			--j;
		if (i <= j) {
			if (i < j) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			i++; j--;
		}
	}

	if (i < last && bit >= 0) bitsort(array, i, last, bit - 1);
	if (first < j && bit >= 0) bitsort(array, first, j, bit - 1);
}