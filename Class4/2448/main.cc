#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define inf 99999999999

ll n;
char arr[4000][7000];

void func(ll k, ll y, ll x){
  if (k == 3){
    arr[y][x] = '*';
    arr[y + 1][x - 1] = '*';
    arr[y + 1][x + 1] = '*';
    for (int i = x - 2; i <= x + 2; i++) arr[y + 2][i] = '*';
    return;
  }
  func(k / 2, y, x);
  func(k / 2, y + (k / 2), x - (k / 2));
  func(k / 2, y + (k / 2), x + (k / 2));
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 0; i < 4000; i++)
    for (int j = 0; j < 7000; j++)
      arr[i][j] = ' ';
  func(n, 0, n - 1);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < (2 * n) - 1; j++)
      cout << arr[i][j];
    cout << "\n";
  }

  return 0;
}
