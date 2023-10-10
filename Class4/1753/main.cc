#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define inf 99999999999

ll v, e, st;
vector<pii> graph[20001];
ll dist[20001];
priority_queue<pii, vector<pii>, greater<pii> > pq; // weight, to

void dijkstra(){
  pq.push(make_pair(0, st));
  while(!pq.empty()){
    ll w = pq.top().first;
    ll t = pq.top().second;
    pq.pop();
    for (int i = 0; i < graph[t].size(); i++){
      ll W = graph[t][i].first;
      ll T = graph[t][i].second;
      if (w + W < dist[T]){
        dist[T] = w + W;
        pq.push(make_pair(w + W, T));
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> v >> e;
  cin >> st;
  for (int i = 1; i <= e; i++){
    ll from, to, weight;
    cin >> from >> to >> weight;
    graph[from].push_back(make_pair(weight, to));
  }
  for (int i = 1; i <= 20000; i++) dist[i] = inf;
  dist[st] = 0;

  dijkstra();
  for (int i = 1; i <= v; i++){
    if (dist[i] == inf) cout << "INF\n";
    else cout << dist[i] << "\n";
  }

  return 0;
}
