#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	int tmp = ((v - b - 1) / (a - b)) + 1;
	printf("%d", tmp);
	return 0;
}
