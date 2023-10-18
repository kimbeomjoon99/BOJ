#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll n, k;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> k;

  vector<pii> gold(n);
  vector<ll> bags(k);
  priority_queue<ll> pq; 

  for (int i = 0; i < n; i++) cin >> gold[i].first >> gold[i].second;
  for (int i = 0; i < k; i++) cin >> bags[i];
  sort(gold.begin(), gold.end());
  sort(bags.begin(), bags.end());

  ll idx = 0, sum = 0;
  for (int i = 0; i < k; i++){
    while(idx < n && gold[idx].first <= bags[i]) pq.push(gold[idx++].second);
    if (!pq.empty()){
      sum += pq.top();
      pq.pop();
    }
  }
  cout << sum << "\n";
  
  return 0;
}
