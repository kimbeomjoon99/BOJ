#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, ll> pii;
#define inf 999999999999

ll n, sum;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++){
    sum += ((n * i) + i);
  }
  cout << sum << "\n";
  
  return 0;
}