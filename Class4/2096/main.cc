#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define inf 999999999

int n, arr[100000][3], dp[2][3], idp[2][3];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++) cin >> arr[i][j];
  for (int i = 0; i < 3; i++){
    dp[0][i] = arr[0][i];
    idp[0][i] = arr[0][i];
  }
  int idx = 1;
  for (int i = 1; i < n; i++){
    dp[idx][0] = max(dp[1^idx][0], dp[1^idx][1]) + arr[i][0];
    idp[idx][0] = min(idp[1^idx][0], idp[1^idx][1]) + arr[i][0];
    dp[idx][1] = max(max(dp[1^idx][0], dp[1^idx][1]), dp[1^idx][2]) + arr[i][1];
    idp[idx][1] = min(min(idp[1^idx][0], idp[1^idx][1]), idp[1^idx][2]) + arr[i][1];
    dp[idx][2] = max(dp[1^idx][1], dp[1^idx][2]) + arr[i][2];
    idp[idx][2] = min(idp[1^idx][1], idp[1^idx][2]) + arr[i][2];
    idx = 1 ^ idx;
  }
  cout << max(max(dp[1^idx][0], dp[1^idx][1]), dp[1^idx][2]) << " ";
  cout << min(min(idp[1^idx][0], idp[1^idx][1]), idp[1^idx][2]) << "\n";

  return 0;
}
