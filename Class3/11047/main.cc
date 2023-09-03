#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, i, j;
    cin >> n >> m;
    vector<ll> coins;
    for (i = 0; i < n; i++){
        ll a;
        cin >> a;
        coins.push_back(a);
    }
    reverse(coins.begin(), coins.end());
    ll ans = 0;
    for (i = 0; i < n; i++){
        if (!(m / coins[i])) continue;
        ans += m / coins[i];
        m = m % coins[i];
        if (!m) break;
    }
    cout << ans << "\n";

    return 0;
}
