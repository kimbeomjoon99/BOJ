#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll n, m;
vector<ll> fir, sec;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++){
    int loc;
    cin >> loc;
    if (loc >= 0) fir.push_back(loc);
    else sec.push_back(abs(loc));
  }
  
  sort(fir.begin(), fir.end());
  sort(sec.begin(), sec.end());
  reverse(fir.begin(), fir.end());
  reverse(sec.begin(), sec.end());
  
  if (!sec.size() || (fir.size() && fir[0] > sec[0])) swap(fir, sec);
  
  ll dist = 0;
  for (int i = 0; i < fir.size(); i += m){
    dist += (fir[i] * 2);
  }
  
  for (int i = 0; i < sec.size(); i += m){
    dist += (sec[i] * 2);
  }
  
  dist -= sec[0];
  cout << dist << "\n";
  
  return 0;
}
