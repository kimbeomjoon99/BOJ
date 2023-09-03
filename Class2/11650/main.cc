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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, i, j;
    cin >> n;
    vector<pair<ll, ll>> locs;
    for (i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        locs.push_back({a, b});
    }
    sort(locs.begin(), locs.end());
    for (i = 0; i < n; i++){
        cout << locs[i].first << " " << locs[i].second << "\n";
    }

    return 0;
}
