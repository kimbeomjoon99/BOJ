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
    
    ll n, k, i, j;
    cin >> n >> k;
    queue<ll> josephus;
    vector<ll> ans;
    for (i = 1; i <= n; i++){
        josephus.push(i);
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < k - 1; j++){
            josephus.push(josephus.front());
            josephus.pop();
        }
        ans.push_back(josephus.front());
        josephus.pop();
    }
    cout << "<";
    for (i = 0; i < n; i++){
        if (i == n - 1) cout << ans[i] << ">\n";
        else cout << ans[i] << ", ";
    }

    return 0;
}
