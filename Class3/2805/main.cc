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
    
    ll m, n, i;
    cin >> n >> m;
    vector<ll> height;
    for (i = 0; i < n; i++){
        ll a;
        cin >> a;
        height.push_back(a);
    }
    sort(height.begin(), height.end());
    ll left = 1, right = height[n - 1], ans = 0;
    while(left <= right){
        ll middle = (left + right) / 2;
        ll woods = 0;
        for (i = 0; i < n; i++){
            if ((height[i] - middle) > 0)
                woods += height[i] - middle;
        }
        if (woods >= m && ans < middle) ans = middle;
        if (woods < m){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
    }
    cout << ans << "\n";

    return 0;
}
