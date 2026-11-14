#include <iostream>
#include "bm.h"

#include <string>
#include <vector>

#include <chrono>
#include <ctime>


using namespace std;

//Реализовать функцию получения индекса первого вхождения подстроки в тексте. 
//Эта функция не должна использовать консольный ввод-вывод.
	int searchfirstBM(string& s, string& p)
	{
		int tab[256], i, j, n, m, k;

		n = s.length();
		m = p.length();

		for (i = 0; i < 256; i++)
			tab[i] = m;

		for (i = 0; i < m - 1; i++)
			tab[p[i]] = m - 1 - i;

		for (i = m - 1, j = m - 1; i < n; i = i + tab[s[i]])
		{
			for (k = i, j = m - 1; j >= 0 && s[k] == p[j]; k = k - 1, j = j - 1)
				if (j <= 0) return k;
		}
		if (i >= n) return -1;
	}

int main() 
{
	setlocale(LC_ALL, "rus");

	string s = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
	string p = "tor";

	auto start = chrono::high_resolution_clock::now();	cout << searchfirstBM(s, p);
	auto end = chrono::high_resolution_clock::now();

	return chrono::duration<double, milli>(end - start).count();

	cout << "затраченное время: " << chrono::duration<double, milli>(end - start).count();
	return 0;
}

