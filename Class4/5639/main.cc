#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define inf 999999999

vector<int> arr;
int n, len;

void postorder(int st, int ed){
  if (st >= ed) return;
  if (st == ed - 1){
    cout << arr[st] << "\n";
    return;
  }
  int idx = st + 1;
  while(idx < ed){
    if (arr[st] < arr[idx]) break;
    idx++;
  }
  postorder(st + 1, idx);
  postorder(idx, ed);
  cout << arr[st] << "\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  while(cin >> n){
    arr.push_back(n);
    len++;
  }
  postorder(0, len);

  return 0;
}
