#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll n, i, j;
    ll cost[1000][3];
    ll dp[1000][3];
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];
    for (i = 1; i < n; i++){
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << "\n";
    
    return 0;
}
