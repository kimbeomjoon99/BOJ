#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

ll n, arr[1001], dp[1001], i, j;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> arr[i];
    dp[1] = 1;
    ll ans = 1;
    for (i = 2; i <= n; i++){
        dp[i] = 1;
        for (j = 0; j < i; j++){
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (dp[i] > ans) ans = dp[i];
    }
    cout << ans << "\n";
    
    return 0;
}
