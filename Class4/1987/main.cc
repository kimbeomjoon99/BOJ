#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define inf 99999999999

ll r, c, ans;
ll visited[256];
char board[20][20];

void bt(ll y, ll x, ll depth){
  if (depth > ans) ans = depth;
  if (y != r - 1 && !visited[board[y + 1][x]]){
    visited[board[y + 1][x]] = 1;
    bt(y + 1, x, depth + 1);
    visited[board[y + 1][x]] = 0;
  }
  if (x != c - 1 && !visited[board[y][x + 1]]){
    visited[board[y][x + 1]] = 1;
    bt(y, x + 1, depth + 1);
    visited[board[y][x + 1]] = 0;
  }
  if (y && !visited[board[y - 1][x]]){
    visited[board[y - 1][x]] = 1;
    bt(y - 1, x, depth + 1);
    visited[board[y - 1][x]] = 0;
  }
  if (x && !visited[board[y][x - 1]]){
    visited[board[y][x - 1]] = 1;
    bt(y, x - 1, depth + 1);
    visited[board[y][x - 1]] = 0;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> r >> c;
  for (int i = 0; i < r; i++){
    string str;
    cin >> str;
    for (int j = 0; j < str.length(); j++)
      board[i][j] = str[j];
  }
  visited[board[0][0]] = 1;
  bt(0, 0, 1);
  cout << ans << "\n";

  return 0;
}
