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
typedef struct vertex{
    vector<struct vertex*> route;
    ll num;
    ll visited;
}vertex;
vector<vertex*> vertice;

ll dfs(ll k){
    if (vertice[k]->visited) return 0;
    vertice[k]->visited++;
    for (ll i = 0; i < vertice[k]->route.size(); i++){
        dfs(vertice[k]->route[i]->num);
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, i;
    cin >> n >> m;
    vertice.push_back(nullptr);
    for (i = 1; i <= n; i++){
        vertex* tmp = new vertex[1];
        tmp->num = i;
        tmp->visited = 0;
        vertice.push_back(tmp);
    }
    for (i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        vertice[u]->route.push_back(vertice[v]);
        vertice[v]->route.push_back(vertice[u]);
    }
    
    ll ans = 0;
    for (i = 1; i <= n; i++){
        ans += dfs(i);
    }
    cout << ans << "\n";
    
    return 0;
}
