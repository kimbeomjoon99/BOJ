#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, ll> pii;
#define inf 999999999999

ll n, m, room[50][50], r, c, d, cnt;
const ll di[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

void dfs(ll y, ll x, ll de){
  if (!room[y][x]){
    room[y][x] = -1;
    cnt++;
    //cout << y << " " << x << " " << cnt << "\n";
  }
  if (room[y - 1][x] && room[y + 1][x] && room[y][x - 1] && room[y][x + 1]){
    if (//(y+di[de][0] == -1 || x+di[de][1] == -1 
        //|| y+di[de][0] >= n || x+di[de][1] >= m) ||
        room[y+di[de][0]][x+di[de][1]] == 1) return;
    dfs(y+di[de][0], x+di[de][1], de);
  }
  else{
    for (int i = 0; i < 4; i++){
      de--;
      if (de == -1) de = 3;
      //if (y-di[de][0] == -1 || x-di[de][1] == -1 
      //    || y-di[de][0] >= n || x-di[de][1] >= m) continue;
      if (!room[y - di[de][0]][x - di[de][1]]){
        dfs(y - di[de][0], x - di[de][1], de);
        break;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  cin >> r >> c >> d;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> room[i][j];
  dfs(r, c, d);
  cout << cnt << "\n";

  return 0;
}