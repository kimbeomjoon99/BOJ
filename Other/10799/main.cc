#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define inf 999999999999

string pipe;
stack<char> s;
ll ans;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> pipe;
  for (int i = 0; i < pipe.length(); i++){
    if (pipe[i] == '('){
      s.push('(');
    }
    else{
      s.pop();
      if (pipe[i - 1] == '(') ans += s.size();
      else ans++;
    }
  }
  cout << ans << "\n";
  
  return 0;
}
