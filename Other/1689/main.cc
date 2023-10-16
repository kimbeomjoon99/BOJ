#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define inf 99999999999

ll n;
vector<pii> lines;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++){
    ll st, ed;
    cin >> st >> ed;
    lines.push_back(make_pair(st, 1));
    lines.push_back(make_pair(ed, -1));
  }
  sort(lines.begin(), lines.end());
  ll cnt = 0, ans = 0;
  for (int i = 0; i < lines.size(); i++){
    cnt += lines[i].second;
    ans = max(ans, cnt);
  }
  cout << ans << "\n";

  return 0;
}
