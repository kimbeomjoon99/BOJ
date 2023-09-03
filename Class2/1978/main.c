#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
	int n;
	scanf("%d", &n);
	int t1, t2;
	int w = 0;
	for (t1 = 0; t1 < n; t1++) {
		int x;
		scanf("%d", &x);
		int p = 0;
		for (t2 = 2; t2 <= x / 2; t2++) {
			if (x % t2 == 0) {
				p = 1;
				break;
			}
		}
		if (x == 1) {
			p = 1;
		}
		if (p == 0) {
			w++;
		}
	}
	printf("%d", w);
	return 0;
}
