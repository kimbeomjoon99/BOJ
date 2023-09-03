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
    
    ll k, n, i, j;
    cin >> k >> n;
    vector<ll> lines;
    for (i = 0; i < k; i++){
        ll a;
        cin >> a;
        lines.push_back(a);
    }
    sort(lines.begin(), lines.end());
    
    ll left = 1, right = lines[k - 1];
    ll ans = 0;
    while(left <= right){
        ll middle = (left + right) / 2;
        ll l = 0;
        for (j = 0; j < k; j++){
            l += lines[j] / middle;
        }
        if (l < n){
            right = middle - 1;
        }
        else {
            left = middle + 1;
            if (ans < middle) ans = middle;
        }
    }
    cout << ans << "\n";

    return 0;
}
