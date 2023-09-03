#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
ll dp[11];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll t, n, i;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (i = 4; i <= 10; i++){
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    cin >> t;
    for (i = 0; i < t; i++){
        ll k;
        cin >> k;
        cout << dp[k] << "\n";
    }

    return 0;
}
