#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int t;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> t;
  for (int k = 0; k < t; k++){
    int n;
    cin >> n;
    vector< vector<int> > arr;
    for (int i = 0; i < 2; i++){
      vector<int> tmp;
      for (int j = 0; j < n; j++){
        int m;
        cin >> m;
        tmp.push_back(m);
      }
      arr.push_back(tmp);
    }
    int res = 0;
    vector<vector<int> > dp;
    vector<int> tmp(n);
    dp.push_back(tmp);
    dp.push_back(tmp);
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    dp[0][1] = arr[1][0] + arr[0][1];
    dp[1][1] = arr[0][0] + arr[1][1];
    for (int i = 2; i < n; i++){
      dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
      dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
  }

  return 0;
}
