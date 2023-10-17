#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define inf 999999999999

string str;
ll m;
stack<char> s, q;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> str;
  for (int i = 0; i < str.length(); i++) s.push(str[i]);
  cin >> m;
  for (int i = 0; i < m; i++){
    char command, content;
    cin >> command;
    if (command == 'L' && !s.empty()){
      q.push(s.top());
      s.pop();
    }
    else if (command == 'D' && !q.empty()){
      s.push(q.top());
      q.pop();
    }
    else if (command == 'B' && !s.empty()) s.pop();
    else if (command == 'P'){
      cin >> content;
      s.push(content);
    }
  }
  deque<char> ans;
  while(!q.empty()){
    ans.push_back(q.top());
    q.pop();
  }
  while(!s.empty()){
    ans.push_front(s.top());
    s.pop();
  }
  for (int i = 0; i < ans.size(); i++) cout << ans[i];
  cout << "\n";
  
  return 0;
}