#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define inf 99999999999

ll t;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> t;
  vector<ll> ans;
  while(t--){
    ll n;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    ll cnt = 1;
    ll std = arr[0].second;
    for (int i = 1; i < n; i++){
      if (arr[i].second < std){
        std = arr[i].second;
        cnt++;
      }
    }
    ans.push_back(cnt);
  }
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

  return 0;
}
