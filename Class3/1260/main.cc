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
    vector<pair<ll, struct vertex*>> connected;
    ll num;
    ll visited;
}vertex;
vector<vertex*> vertice;

void dfs(ll k){
    if (vertice[k]->visited) return;
    cout << vertice[k]->num << " ";
    vertice[k]->visited = 1;
    for (ll i = 0; i < vertice[k]->connected.size(); i++){
        dfs(vertice[k]->connected[i].second->num);
    }
}

void bfs(ll k){
    queue<vertex*> q;
    q.push(vertice[k]);
    vertice[k]->visited = 1;
    while(!q.empty()){
        cout << q.front()->num << " ";
        for (ll i = 0; i < q.front()->connected.size(); i++){
            if (!q.front()->connected[i].second->visited){
                q.front()->connected[i].second->visited = 1;
                q.push(q.front()->connected[i].second);
            }
        }
        q.pop();
    }
}

void Clear(){
    for (ll i = 1; i < vertice.size(); i++){
        vertice[i]->visited = 0;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, v, i, j;
    cin >> n >> m >> v;
    vertice.push_back(nullptr);
    for (i = 1; i <= n; i++){
        vertex* tmp = new vertex[1];
        tmp->num = i;
        tmp->visited = 0;
        vertice.push_back(tmp);
    }
    for (i = 1; i <= m; i++){
        ll a, b;
        cin >> a >> b;
        vertice[a]->connected.push_back({b, vertice[b]});
        vertice[b]->connected.push_back({a, vertice[a]});
    }
    for (i = 1; i <= n; i++){
        sort(vertice[i]->connected.begin(), vertice[i]->connected.end());
    }
    dfs(v);
    cout << "\n";
    Clear();
    bfs(v);
    cout << "\n";

    return 0;
}
