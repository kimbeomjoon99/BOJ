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
    vector<ll> loc, simple;
    for (i = 0; i < n; i++){
        ll a;
        cin >> a;
        loc.push_back(a);
        simple.push_back(a);
    }
    sort(loc.begin(), loc.end());
    loc.erase(unique(loc.begin(), loc.end()), loc.end());
    
    for (i = 0; i < n; i++){
        cout << lower_bound(loc.begin(), loc.end(), simple[i]) - loc.begin() << " ";
    }
    cout << "\n";
    
    return 0;
}
