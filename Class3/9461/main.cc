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
ll dp[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    ll t, i;
    for (i = 6; i <= 100; i++){
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    cin >> t;
    
    for (i = 0; i < t; i++){
        ll n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    
    return 0;
}
