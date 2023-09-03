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

ll getgcd(ll a, ll b){
    ll k = a % b;
    if (!k) return b;
    else return getgcd(b, k);
}

ll getlcm(ll a, ll b){
    ll k = getgcd(a, b);
    ll m = k;
    while((k % a) || (k % b)){
        k += m;
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll a, b;
    cin >> a >> b;

    cout << getgcd(a, b) << "\n";
    cout << getlcm(a, b) << "\n";

    return 0;
}
