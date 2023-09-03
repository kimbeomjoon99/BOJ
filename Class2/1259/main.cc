#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);

	
	while (1) {
		string str;
		cin >> str;
		if (str[0] == '0') break;
		string tmp = str;
		reverse(tmp.begin(), tmp.end());
		if (tmp == str) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
