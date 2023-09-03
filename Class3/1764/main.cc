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
string num_find[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, i, j;
    cin >> n >> m;
    vector<string> ans;
    set<string> s;
    for (i = 0; i < n; i++){
        string k;
        cin >> k;
        s.insert(k);
    }
    for (i = 0; i < m; i++){
        string k;
        cin >> k;
        if (s.find(k) != s.end()){
            ans.push_back(k);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
