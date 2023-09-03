#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define inf 999999999

int n, m, arr[1000][1000], dist[1000][1000], visited[1000][1000];
pii st;

void bfs(){
  queue<pair<pii, int> > q;
  q.push(make_pair(st, 0));
  visited[st.first][st.second] = 1;
  while(!q.empty()){
    pii here = q.front().first;
    dist[here.first][here.second] = q.front().second;
    if (here.first && !visited[here.first - 1][here.second] &&
        arr[here.first - 1][here.second] == 1){
      q.push(make_pair(make_pair(here.first - 1, here.second), q.front().second + 1));
      visited[here.first - 1][here.second] = 1;
    }
    if (here.second && !visited[here.first][here.second - 1] &&
        arr[here.first][here.second - 1] == 1){
      q.push(make_pair(make_pair(here.first, here.second - 1), q.front().second + 1));
      visited[here.first][here.second - 1] = 1;
    }
    if (here.first < n - 1 && !visited[here.first + 1][here.second] &&
        arr[here.first + 1][here.second] == 1){
      q.push(make_pair(make_pair(here.first + 1, here.second), q.front().second + 1));
      visited[here.first + 1][here.second] = 1;
    }
    if (here.second < m - 1 && !visited[here.first][here.second + 1] &&
        arr[here.first][here.second + 1] == 1){
      q.push(make_pair(make_pair(here.first, here.second + 1), q.front().second + 1));
      visited[here.first][here.second + 1] = 1;
    }
    q.pop();
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> arr[i][j];
      if (arr[i][j] == 2){
        st.first = i;
        st.second = j;
      }
      if (!arr[i][j]) dist[i][j] = 0;
      else dist[i][j] = -1;
    }
  }

  bfs();
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << dist[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
