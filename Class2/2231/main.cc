#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, i;
    cin >> n;
    int ans = 0;

    for (i = 1; i < n; i++){
        if (i < 10){
            if (i + i == n){
                cout << i << "\n";
                return 0;
            }
        }
        else if (i < 100){
            int a = i / 10;
            int b = i % 10;
            if (i + a + b == n){
                cout << i << "\n";
                return 0;
            }
        }
        else if (i < 1000){
            int a = i / 100;
            int b = (i % 100) / 10;
            int c = i % 10;
            if (i + a + b + c == n){
                cout << i << "\n";
                return 0;
            }
        }
        else if (i < 10000){
            int a = i / 1000;
            int b = (i % 1000) / 100;
            int c = (i % 100) / 10;
            int d = i % 10;
            if (i + a + b + c + d == n){
                cout << i << "\n";
                return 0;
            }
        }
        else if (i < 100000){
            int a = i / 10000;
            int b = (i % 10000) / 1000;
            int c = (i % 1000) / 100;
            int d = (i % 100) / 10;
            int e = i % 10;
            if (i + a + b + c + d + e == n){
                cout << i << "\n";
                return 0;
            }
        }
        else if (i < 1000000){
            int a = i / 100000;
            int b = (i % 100000) / 10000;
            int c = (i % 10000) / 1000;
            int d = (i % 1000) / 100;
            int e = (i % 100) / 10;
            int f = i % 10;
            if (i + a + b + c + d + e + f == n){
                cout << i << "\n";
                return 0;
            }
        }
    }
    cout << 0 << "\n";

    return 0;
}
