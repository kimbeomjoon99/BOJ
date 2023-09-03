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
ll dp[50001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, i, j;
    cin >> n;
    dp[1] = 1;
    for (i = 2; i <= n; i++){
        dp[i] = 1 + dp[i - 1];
        for (j = 2; j * j <= i; j++){
            dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
        }
    }
    cout << dp[n] << "\n";

    return 0;
}
