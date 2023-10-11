#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define inf 99999999999

ll n, e, u, v, ans;
vector<pii> graph[801];
ll dist[801];
priority_queue<pii, vector<pii>, greater<pii> > pq; // weight, to

void dijkstra(ll st){
  dist[st] = 0;
  pq.push(make_pair(0, st));
  while(!pq.empty()){
    ll weight = pq.top().first;
    ll to = pq.top().second;
    pq.pop();
    for (int i = 0; i < graph[to].size(); i++){
      ll w = graph[to][i].first;
      ll t = graph[to][i].second;
      if (weight + w < dist[t]){
        dist[t] = weight + w;
        pq.push(make_pair(weight + w, t));
      }
    }
  }
}

void Clear(){
  while(!pq.empty()) pq.pop();
  for (int i = 0; i <= n; i++) dist[i] = inf;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> e;
  for (int i = 0; i < e; i++){
    ll from, to, weight;
    cin >> from >> to >> weight;
    graph[from].push_back(make_pair(weight, to));
    graph[to].push_back(make_pair(weight, from));
  }
  cin >> u >> v;

  Clear();
  dijkstra(1);
  ans += dist[u];
  Clear();
  dijkstra(u);
  ans += dist[v];
  Clear();
  dijkstra(v);
  ans += dist[n];

  Clear();
  dijkstra(1);
  ll tmp = dist[v];
  Clear();
  dijkstra(v);
  tmp += dist[u];
  Clear();
  dijkstra(u);
  tmp += dist[n];

  if (tmp < ans) ans = tmp;

  if (ans < inf) cout << ans << "\n";
  else cout << -1 << "\n";

  return 0;
}
