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
typedef int ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, i;
    cin >> n;
    vector<pair<ll, ll>> table;
    for (i = 0; i < n; i++){
        ll st, ed;
        cin >> st >> ed;
        table.push_back({ed, st});
    }
    sort(table.begin(), table.end());
    vector<pair<ll, ll>> ans;
    for (i = 0; i < n; i++){
        if (!i) {
            ans.push_back({table[0].second, table[0].first});
            continue;
        }
        if (table[i].second < ans[ans.size() - 1].second) continue;
        else ans.push_back({table[i].second, table[i].first});
    }
    cout << ans.size() << "\n";

    return 0;
}
