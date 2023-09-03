#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
typedef long long ll;
using namespace std;
ll cards[20000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, i, j, m;
    cin >> n;
    for (i = 1; i <= n; i++){
        ll a;
        cin >> a;
        cards[a + 10000000]++;
    }
    vector<ll> key, ans;
    cin >> m;
    for (i = 0; i < m; i++){
        ll a;
        cin >> a;
        key.push_back(a);
    }
    for (i = 0; i < m; i++){
        ans.push_back(cards[key[i] + 10000000]);
    }
    for (i = 0; i < m; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
