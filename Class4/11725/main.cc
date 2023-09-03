#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define INF 999999999;

ll n, parent[100001], visited[100001];
vector<ll> graph[100001];

void bfs(){
    ll here = 1;
    visited[here] = 1;
    queue<ll> q;
    q.push(here);
    while(!q.empty()){
        here = q.front();
        visited[here] = 1;
        q.pop();
        for (ll i = 0; i < graph[here].size(); i++){
            if (visited[graph[here][i]]) continue;
            parent[graph[here][i]] = here;
            q.push(graph[here][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    for (ll i = 0; i < n - 1; i++){
        ll from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    bfs();
    for (ll i = 2; i <= n; i++) cout << parent[i] << "\n";

    return 0;
}
