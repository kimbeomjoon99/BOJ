#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, string> pii;
#define inf 99999999999

ll n, m, truth, ans;
ll parent[51], check[51];
vector<vector<ll> > party;

ll search(ll num){
  if (parent[num] == num) return num;
  else return search(parent[num]);
}

void Union(ll a, ll b){
  ll c = search(a);
  ll d = search(b);
  parent[c] = d;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  cin >> truth;
  for (int i = 1; i <= truth; i++){
    ll num;
    cin >> num;
    check[i] = num;
  }
  for (int i = 1; i <= n; i++) parent[i] = i;

  for (int i = 1; i <= m; i++){
    ll num, prev;
    cin >> num;
    vector<ll> arr;
    for (int j = 1; j <= num; j++){
      int tmp;
      cin >> tmp;
      arr.push_back(tmp);
      if (j >= 2) Union(prev, tmp);
      prev = tmp;
    }
    party.push_back(arr);
  }

  for (int i = 0; i < m; i++){
    int flag = 0;
    for (int j = 0; j < party[i].size(); j++){
      for (int k = 1; k <= truth; k++){
        if (search(check[k]) == search(party[i][j])){
          flag++;
          break;
        }
      }
    }
    if (!flag) ans++;
  }
  cout << ans << "\n";

  return 0;
}
