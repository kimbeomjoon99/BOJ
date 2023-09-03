#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
typedef unsigned long ll;
using namespace std;
ll r = 1;
ll m = 1234567891;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // a = 97
    ll l;
    cin >> l;

    cin >> s;

    vector<ll> arr;
    for (ll i = 0; i < l; i++){
        arr.push_back(s[i] - 96);
    }
    ll ans = 0;
    for (ll i = 0; i < l; i++){
        ans += arr[i] * r;
        ans %= m;
        r *= 31;
        r %= m;
    }
    cout << ans << "\n";

    return 0;
}
