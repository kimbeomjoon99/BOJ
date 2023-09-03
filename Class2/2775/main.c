#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
	int t;
	scanf("%d", &t);
	int t1, t2, t3, t4;
	for (t1 = 0; t1 < t; t1++) {
		int k, n;
		scanf("%d", &k);
		scanf("%d", &n);
		int** apart = (int**)malloc(sizeof(int*) * (k + 1));
		for (t2 = 0; t2 < k + 1; t2++) {
			apart[t2] = (int*)malloc(sizeof(int) * n);
		}
		for (t2 = 0; t2 < k + 1; t2++) {
			for (t3 = 0; t3 < n; t3++) {
				apart[t2][t3] = 0;
			}
		}
		for (t2 = 0; t2 < n; t2++) {
			apart[0][t2] = t2 + 1;
		}
		for (t2 = 1; t2 < k + 1; t2++) {
			for (t3 = 0; t3 < n; t3++) {
				for (t4 = 0; t4 <= t3; t4++) {
					apart[t2][t3] = apart[t2][t3] + apart[t2 - 1][t4];
				}
			}
		}
		printf("%d\n", apart[k][n - 1]);
	}
	return 0;
}
