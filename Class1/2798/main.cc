#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(0); //동기화하는 시간이 있어 시간이 오래걸림 -> 동기화를 해제하는 코드
	std::cin.tie(0), std::cout.tie(0);

	int n, m;
	cin >> n >> m;
	int t1, t2, t3;
	int* card = new int[n];
	for (t1 = 0; t1 < n; t1++) {
		cin >> card[t1];
	}
	int sum = 0;
	for (t1 = 0; t1 < n; t1++) {
		for (t2 = t1 + 1; t2 < n; t2++) {
			for (t3 = t2 + 1; t3 < n; t3++) {
				int tempsum = card[t1] + card[t2] + card[t3];
				if (tempsum > m) continue;
				if (tempsum > sum) sum = tempsum;
			}
		}
	}
	delete[] card;
	cout << sum;
	return 0;
}
