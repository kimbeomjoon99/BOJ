#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
	int n;
	scanf("%d", &n);
	int d = n / 5;
	int t1, t2;
	int f = 0;
	int g = 0;
	for (t1 = 1; t1 <= d; t1++) {
		if ((n - (5 * t1)) % 3 == 0) {
			f = t1;
		}
	}
	if (f != 0) {
		n = n - (5 * f);
	}
	int e = n / 3;
	for (t1 = 1; t1 <= e; t1++) {
		if (n - (3 * e) == 0){
			g = e;
		}
	}
	int a = f + e;
	if (f == 0 && g == 0) {
		a = -1;
	}
	printf("%d", a);
	return 0;
}
