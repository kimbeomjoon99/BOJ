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

ll getgcd(ll a, ll b){
    ll k = a % b;
    if (!k) return b;
    else return getgcd(b, k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll t, i, j;
    cin >> t;
    for (i = 0; i < t; i++){
        ll n, m, x, y;
        cin >> m >> n >> x >> y;
        ll ed = (m * n) / getgcd(m, n);
        ll p, flag = 0;;
        for (j = x; j <=ed; j += m){
            if (!(j % n)) p = n;
            else p = j % n;
            if (p == y){
                flag++;
                break;
            }
        }
        if (flag) cout << j << "\n";
        else cout << - 1 << "\n";
    }

    return 0;
}
