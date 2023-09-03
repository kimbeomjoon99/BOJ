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
ll arr[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, i, j;
    cin >> n;
    vector<ll> key, ans;
    for (i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cin >> m;
    for (i = 0; i < m; i++){
        ll a;
        cin >> a;
        key.push_back(a);
    }
    sort(arr + 1, arr + n + 1);
    
    for (i = 0; i < m; i++){
        ll left = 1, right = n;
        ll flag = 0;
        while(left <= right){
            ll middle = (left + right) / 2;
            if (arr[middle] == key[i]){
                flag++;
                break;
            }
            else if (arr[middle] > key[i]) right = middle - 1;
            else left = middle + 1;
        }
        if (flag) ans.push_back(1);
        else ans.push_back(0);
    }
    for (i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }
    
    return 0;
}
