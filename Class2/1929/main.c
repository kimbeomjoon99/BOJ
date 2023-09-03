#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int prime[1001] = { 0 };
	int arr[1000001] = { 0 };
	arr[1] = 1;
	int t1, t2;
	for (t1 = 2; t1 <= 1000; t1++) {
		int p = 0;
		for (t2 = 2; t2 < t1; t2++) {
			if (t1 % t2 == 0) {
				p = 1;
				break;
			}
		}
		if (p == 0) {
			prime[t1] = 1;
		}
	}
	for (t1 = 2; t1 <= 1000; t1++) {
		if (prime[t1] == 1) {
			int t = t1 + t1;
			while (1) {
				arr[t] = 1;
				t = t + t1;
				if (t >= 1000000) {
					break;
				}
			}
		}
	}
	for (t1 = m; t1 <= n; t1++) {
		if (arr[t1] == 0) {
			printf("%d\n", t1);
		}
	}
	return 0;
}
