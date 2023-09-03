#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

ll n, i, j, room[17][17], dp[17][17][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> room[i][j];
    dp[1][2][0] = 1, dp[1][2][1] = dp[1][2][2] = 0;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if ((i == 1 && j <= 2) || room[i][j]) continue;
            if (!room[i][j - 1])
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
            if (!room[i - 1][j])
                dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
            if (!room[i][j - 1] && !room[i - 1][j])
                dp[i][j][2] = dp[i - 1][j - 1][0]
                + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << "\n";
    
    return 0;
}
