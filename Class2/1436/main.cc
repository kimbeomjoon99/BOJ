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
    
    ll n;
    cin >> n;
    
    ll num = 0, cnt = 0;
    while(1){
        num++;
        ll tmp = num;
        while(tmp){
            if (tmp % 1000 == 666){
                cnt++;
                break;
            }
            tmp = tmp / 10;
        }
        if (cnt == n) break;
    }

    cout << num << "\n";

    return 0;
}
