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
    priority_queue<ll> pq;
    for (i = 0; i < n; i++){
        ll x;
        cin >> x;
        if (!x && pq.empty()) cout << 0 << "\n";
        else if (!x) {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else pq.push(x);
    }

    return 0;
}
