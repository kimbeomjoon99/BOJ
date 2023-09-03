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
ll dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, i;
    cin >> n;
    for (i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + 1;
        if (!(i % 3))
            dp[i] = min(dp[i], dp[i / 3] + 1);
        if (!(i % 2))
            dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    cout << dp[n] << "\n";

    return 0;
}
