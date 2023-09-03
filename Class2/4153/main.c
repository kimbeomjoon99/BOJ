#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		if (((a * a) + (b * b)) == c * c || ((a * a) + (c * c)) == b * b || ((c * c) + (b * b)) == a * a) {
			printf("right\n");
			continue;
		}
		else {
			printf("wrong\n");
		}
	}
	return 0;
}
