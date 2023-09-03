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
// '0' = 48

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll m, i, j;
    string n;
    cin >> n;
    cin >> m;
    if (!m) {
        if (stoi(n) >= 96 && stoi(n) <= 104) cout << abs(100 - stoi(n)) << "\n";
        else cout << n.length() << "\n";
        return 0;
    }
    set<char> broken;
    for (i = 0; i < m; i++){
        char a;
        cin >> a;
        broken.insert(a);
    }
    ll ans = abs(100 - stoi(n));
    for (i = 0; i <= 1000000; i++){
        ll flag = 0;
        string tmp = to_string(i);
        for (j = 0; j < tmp.length(); j++){
            if (broken.find(tmp[j]) != broken.end()){
                flag++;
                break;
            }
        }
        if (flag) continue;
        ll k = abs(stoi(n) - stoi(tmp)) + tmp.length();
        //if (tmp.length() < n.length()) k -= n.length() - tmp.length();
        ans = min(ans, k);
        
    }
    cout << ans << "\n";

    return 0;
}
