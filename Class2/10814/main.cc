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
    vector<pair<ll, pair<ll, string>>> List;
    for (i = 1; i <= n; i++){
        ll a;
        string b;
        cin >> a >> b;
        List.push_back({a, {i, b}});
    }
    sort(List.begin(), List.end());
    for (i = 0; i < n; i++){
        cout << List[i].first << " " << List[i].second.second << "\n";
    }

    return 0;
}
