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
    
    ll t, i, j;
    cin >> t;
    for (i = 0; i < t; i++){
        ll n;
        cin >> n;
        map<string, ll> clothes;
        ll ans = 1;
        for (j = 0; j < n; j++){
            string a, b;
            cin >> a >> b;
            if (clothes.find(b) == clothes.end()){
                clothes.insert({b, 1});
            }
            else {
                clothes[b]++;
            }
        }
        for (auto iter : clothes){
            ans *= iter.second + 1;
        }
        cout << ans - 1 << "\n";
    }

    return 0;
}
