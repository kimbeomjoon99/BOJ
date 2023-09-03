#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int n, m, arr[1024][1024], dp[1025][1025];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] + arr[i][j] - dp[i][j];
    }
  }

  for (int i = 0; i < m; i++){
    int x1, y1, x2, y2, ans;
    cin >> x1 >> y1 >> x2 >> y2;
    ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
    cout << ans << "\n";
  }

  return 0;
}
