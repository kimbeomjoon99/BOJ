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

ll dnc(ll k, ll r, ll c) {
    if (k == 2) {
        return ((r % 2) * 2) + (c % 2);
    }
    ll ans;
    if (r < k / 2 && c < k / 2) {
        ans = dnc(k / 2, r, c);
    }
    else if (r < k / 2 && c >= k / 2) {
        ans = dnc(k / 2, r, c - (k / 2)) + (k * (k / 4));
    }
    else if (r >= k / 2 && c < k / 2) {
        ans = dnc(k / 2, r - (k / 2), c) + (2 * (k * (k / 4)));
    }
    else {
        ans = dnc(k / 2, r - (k / 2), c - (k / 2)) + (3 * (k * (k / 4)));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, r, c;
    cin >> n >> r >> c;
    cout << dnc((ll)pow(2, n), r, c) << "\n";

    return 0;
}
