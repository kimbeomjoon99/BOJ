#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int arr[9];
void dfs(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
   
	int n, m;
	cin >> n >> m;

	dfs(n, m, 0);

	return 0;
}

void dfs(int n, int m, int depth) {
	int i, j, k;
	if (depth == m) {
		int flag = 0;
		for (i = 0; i < m; i++) {
			int Flag = 0;
			for (j = 0; j < m; j++) {
				if (i == j) continue;
				if (arr[i] == arr[j]) {
					Flag++;
					break;
				}
			}
			if (Flag) {
				flag++;
				break;
			}
		}
		if (flag) return;

		flag = 0;
		for (i = 0; i < m - 1; i++) {
			if (arr[i + 1] <= arr[i]) {
				flag++;
				break;
			}
		}
		if (flag) return;

		for (i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (i = 0; i < n; i++) {
		arr[depth] = i + 1;
		dfs(n, m, depth + 1);
	}
}
