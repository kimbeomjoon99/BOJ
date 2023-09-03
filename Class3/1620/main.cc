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
    
    map<string, ll> str_find;
    for (i = 1; i <= n; i++){
        string k;
        cin >> k;
        num_find[i] = k;
        str_find.insert({k, i});
    }
    for (i = 1; i <= m; i++){
        string k;
        cin >> k;
        if (k[0] >= 48 && k[0] <= 57){
            ll num = stoll(k);
            cout << num_find[num] << "\n";
        }
        else{
            cout << str_find.find(k)->second << "\n";
        }
    }

    return 0;
}
