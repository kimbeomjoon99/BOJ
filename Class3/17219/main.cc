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
    
    ll n, m, i;
    cin >> n >> m;
    map<string, string> pwds;
    for (i = 0; i < n; i++){
        string s, k;
        cin >> s >> k;
        pwds.insert({s, k});
    }
    for (i = 0; i < m; i++){
        string s;
        cin >> s;
        cout << pwds.find(s)->second << "\n";
    }

    return 0;
}
