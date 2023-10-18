#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, ll> pii;
#define inf 999999999999

ll n, k;
string str;
stack<char> s;
vector<char> ans;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> k;
  cin >> str;
  for (int i = 0; i < n; i++){
    while(!s.empty() && s.top() < str[i] && k > 0){
      s.pop();
      k--;
    }
    s.push(str[i]);
  }
  while(!s.empty()){
    if (k > 0){
      s.pop();
      k--;
      continue;
    }
    ans.push_back(s.top());
    s.pop();
  }
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
  cout << "\n";
  
  return 0;
}