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

    ll n, i;
    cin >> n;
    priority_queue<pair<ll, bool>> pq;
    for (i = 0; i < n; i++) {
        ll k;
        cin >> k;
        if (pq.empty() && !k) cout << 0 << "\n";
        else if (!k) {
            if (!pq.top().second) {
                cout << -pq.top().first << "\n";
            }
            else {
                cout << pq.top().first << "\n";
            }
            pq.pop();
        }
        else {
            if (k < 0) pq.push({ k, true });
            else pq.push({ -k, false });
        }
    }

    return 0;
}
