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
ll cost[101][101];
ll bacon[101];
#define inf 999999999

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, i, j, k;
    cin >> n >> m;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            cost[i][j] = inf;
        }
    }
    for (i = 1; i <= m; i++){
        ll u, v;
        cin >> u >> v;
        cost[u][v] = 1;
        cost[v][u] = 1;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            for (k = 1; k <= n; k++)
                if (cost[j][i] + cost[i][k] < cost[j][k])
                    cost[j][k] = cost[j][i] + cost[i][k];
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i == j) continue;
            bacon[i] += cost[i][j];
        }
    }
    ll ans = inf;
    ll res;
    for (i = 1; i <= n; i++){
        if (bacon[i] < ans){
            ans = bacon[i];
            res = i;
        }
    }
    cout << res << "\n";

    return 0;
}
