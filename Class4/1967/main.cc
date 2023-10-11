#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define inf 99999999999

ll n, e, u, v, ans, point;
vector<pii> graph[10001];
ll visited[10001];

void dfs(int here, int dist){
  if (visited[here]) return;
  visited[here]++;
  if (ans < dist){
    ans = dist;
    point = here;
  }
  for (int i = 0; i < graph[here].size(); i++)
    dfs(graph[here][i].first, dist + graph[here][i].second);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 0; i < n - 1; i++){
    ll from, to, weight;
    cin >> from >> to >> weight;
    graph[from].push_back(make_pair(to, weight));
    graph[to].push_back(make_pair(from, weight));
  }

  dfs(1, 0);
  ans = 0;
  for (int i = 0; i <= n; i++) visited[i] = 0;
  dfs(point, 0);
  cout << ans << "\n";

  return 0;
}
