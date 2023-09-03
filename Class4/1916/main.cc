#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define inf 999999999;

int m, n, st, ed;
int cost[1001][1001], dist[1001], visited[1001];

void dijkstra(int s){
  for (int i = 1; i <= n; i++)
    dist[i] = cost[s][i];
  visited[s] = 1;
  for (int i = 1; i <= n; i++){
    int curr, d = inf;
    for (int j = 1; j <= n; j++){
      if (dist[j] < d && !visited[j]){
        d = dist[j];
        curr = j;
      }
    }
    visited[curr] = 1;
    for (int j = 1; j <= n; j++){
      if (!visited[j]){
        dist[j] = min(dist[j], dist[curr] + cost[curr][j]);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  for (int i = 1; i <= 1000; i++)
    for (int j = 1; j <= 1000; j++){
      if (i == j) cost[i][j] = 0;
      else cost[i][j] = inf;
    }

  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int from, to, c;
    cin >> from >> to >> c;
    if (from == to) continue;
    if (c < cost[from][to])
      cost[from][to] = c;
  }
  cin >> st >> ed;
  dijkstra(st);
  cout << dist[ed] << "\n";

  return 0;
}
