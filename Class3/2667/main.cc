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
typedef int ll;
using namespace std;
vector<string> Map;
ll visited[25][25];
ll n;

ll dfs(ll y, ll x){
    if (Map[y][x] == '0') return 0;
    if (visited[y][x]) return 0;
    visited[y][x]++;
    ll ans = 1;
    if (y != n - 1 && Map[y + 1][x] == '1' && !visited[y + 1][x]){
        ans += dfs(y + 1, x);
    }    
    if (x != n - 1 && Map[y][x + 1] == '1' && !visited[y][x + 1]){
        ans += dfs(y, x + 1);
    }
    if (y && Map[y - 1][x] == '1' && !visited[y - 1][x]){
        ans += dfs(y - 1, x);
    }
    if (x && Map[y][x - 1] == '1' && !visited[y][x - 1]){
        ans += dfs(y, x - 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll i, j;
    cin >> n;
    for (i = 0; i < n; i++){
        string s;
        cin >> s;
        Map.push_back(s);
    }
    ll res = 0;
    vector<ll> ans;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            ll k = dfs(i, j);
            if (k){
                res++;
                ans.push_back(k);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << res << "\n";
    for (i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
