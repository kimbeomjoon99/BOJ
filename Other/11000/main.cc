#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll n;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n;
  vector<pii> arr(n);
  priority_queue<ll, vector<ll>, greater<ll> > pq;

  for (int i = 0; i < n; i++){
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr.begin(), arr.end());

  pq.push(arr[0].second);
  for (int i = 1; i < n; i++){
    if (pq.top() <= arr[i].first) pq.pop();
    pq.push(arr[i].second);
  }
  cout << pq.size() << "\n";
  
  return 0;
}
