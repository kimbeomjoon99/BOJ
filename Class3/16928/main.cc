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
//#include <map>
typedef int ll;
using namespace std;
ll map[110];
ll visited[110];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll n, m, i, j, k;
    queue<ll> q;
    cin >> n >> m;
    for (i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        map[x] = y;
    }
    for (i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        map[u] = v;
    }

    q.push(1);
    visited[1]++;

    ll ans = -1;
    while(1){
        ans++;
        ll s = q.size();
        ll flag = 0;
        for (i = 0; i < s; i++){
            if (q.front() == 100){
                flag++;
                break;
            }
            for (j = q.front() + 1; j <= q.front() + 6; j++){
                if (map[j]){
                    k = j;
                    while(map[k]){
                        k = map[k];
                    }
                    if (!visited[k]){
                        q.push(k);
                        visited[k]++;
                    }
                }
                else if (!visited[j]){
                    q.push(j);
                    visited[j]++;
                }
            }
            q.pop();
        }
        if (flag) break;
    }
    cout << ans << "\n";

    return 0;
}
