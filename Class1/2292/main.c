#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
	int n;
	scanf("%d", &n);
	int s = 1;
	int i = 1;
	int p = 0;
	int w = 1;
	while (1) {
		if (n >= i && n <= s) {
			p++;
			break;
		}
		else {
			i = s + 1;
			s = s + (w * 6);
			p++;
			w++;
			continue;
		}
	}
	printf("%d", w);
	return 0;
}
