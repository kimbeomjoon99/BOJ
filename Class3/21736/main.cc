#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define inf 999999999

int n, m, cnt = 0;
int campus[600][600], visited[600][600];
pii st;

void bfs(){
  queue<pii> q;
  q.push(st);
  while(!q.empty()){
    pii curr = q.front();
    q.pop();
    cnt += campus[curr.first][curr.second];
    if (!visited[curr.first - 1][curr.second] && curr.first
        && campus[curr.first - 1][curr.second] != -1){
      q.push(make_pair(curr.first - 1, curr.second));
      visited[curr.first - 1][curr.second] = 1;
    }
    if (!visited[curr.first + 1][curr.second] && curr.first != n - 1
        && campus[curr.first + 1][curr.second] != -1){
      q.push(make_pair(curr.first + 1, curr.second));
      visited[curr.first + 1][curr.second] = 1;
    }
    if (!visited[curr.first][curr.second - 1] && curr.second
        && campus[curr.first][curr.second - 1] != -1){
      q.push(make_pair(curr.first, curr.second - 1));
      visited[curr.first][curr.second - 1] = 1;
    }
    if (!visited[curr.first][curr.second + 1] && curr.second != m - 1
        && campus[curr.first][curr.second + 1] != -1){
      q.push(make_pair(curr.first, curr.second + 1));
      visited[curr.first][curr.second + 1] = 1;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++){
    string tmp;
    cin >> tmp;
    for (int j = 0; j < tmp.size(); j++){
      if (tmp[j] == 'I'){
        st.first = i;
        st.second = j;
        visited[i][j] = 1;
      }
      else if (tmp[j] == 'X') campus[i][j] = -1;
      else if (tmp[j] == 'P') campus[i][j] = 1;
    }
  }

  bfs();
  if (!cnt) cout << "TT\n";
  else cout << cnt << "\n";

  return 0;
}
