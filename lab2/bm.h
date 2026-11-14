#pragma once

int SearchBM(char s[], char p[], int m, int n, int TAB[]) {
	int i, j, k;
	i = m - 1;
	j = m - 1;
	while (i < n) {
		k = i;
		j = m - 1;
		while (j >= 0) {
			if (s[k] == p[j]) {
				k--;
				j--;
			}
			else {
				i += TAB[s[i]];
				break;
			}
		}
		if (j < 0)
			return k + 1;
	}
	return 0;
}
