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
    vector<ll> arr;
    for (i = 0; i < n; i++){
        ll a;
        cin >> a;
        arr.push_back(a);
    }
    ll sum = 0, ans = 0;
    sort(arr.begin(), arr.end());
    for (i = 0; i < n; i++){
        ans += arr[i] + sum;
        sum += arr[i];
    }
    cout << ans << "\n";

    return 0;
}
