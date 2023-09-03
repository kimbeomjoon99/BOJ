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
ll dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, i;
    dp[1] = 1;
    dp[2] = 2;
    cin >> n;
    for (i = 3; i <= n; i++){
        dp[i] = ((dp[i - 2] % 10007) + (dp[i - 1] % 10007)) % 10007;
    }
    cout << dp[n] << "\n";

    return 0;
}
