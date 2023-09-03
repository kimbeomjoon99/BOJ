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
ll G[50][50];
ll visited[50][50];

ll dfs(ll m, ll n){
    if (!G[m][n] || visited[m][n]) return 0;
    visited[m][n] = 1;
    if (m != 49 && G[m + 1][n] && !visited[m + 1][n])
        dfs(m + 1, n);
    if (n != 49 && G[m][n + 1] && !visited[m][n + 1])
        dfs(m, n + 1);
    if (m && G[m - 1][n] && !visited[m - 1][n])
        dfs(m - 1, n);
    if (n && G[m][n - 1] && !visited[m][n - 1])
        dfs(m, n - 1);
    return 1;
}

void Clear(){
    ll i, j;
    for (i = 0; i < 50; i++){
        for (j = 0; j < 50; j++){
            G[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll t, i, j, l;
    cin >> t;
    for (i = 0; i < t; i++){
        ll m, n, k;
        cin >> m >> n >> k;
        for (j = 0; j < k; j++){
            ll a, b;
            cin >> a >> b;
            G[a][b]++;
        }
        ll ans = 0;
        for (j = 0; j < m; j++){
            for (l = 0; l < n; l++){
                ans += dfs(j, l);
            }
        }
        cout << ans << "\n";
        Clear(); 
    }

    return 0;
}
