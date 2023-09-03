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
ll segtree[400004];
ll arr[100001];

void makesegtree(ll node, ll st, ll ed){
    if (st == ed) segtree[node] = arr[st];
    else {
        ll middle = (st + ed) / 2;
        makesegtree(node * 2, st, middle);
        makesegtree((node * 2) + 1, middle + 1, ed);
        segtree[node] = segtree[node * 2] + segtree[(node * 2) + 1];
    }
    return;
}

ll query(ll node, ll st, ll ed, ll left, ll right){
    if (st >= left && ed <= right) return segtree[node];
    else if (st > right || ed < left) return 0;
    else{
        ll middle = (st + ed) / 2;
        ll a = query(node * 2, st, middle, left, right);
        ll b = query((node * 2) + 1, middle + 1, ed, left, right);
        return a + b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, i;
    cin >> n >> m;
    for (i = 1; i <= n; i++){
        cin >> arr[i];
    }
    makesegtree(1, 1, n);
    for (i = 0; i < m; i++){
        ll left, right;
        cin >> left >> right;
        cout << query(1, 1, n, left, right) << "\n";
    }
    
    return 0;
}
