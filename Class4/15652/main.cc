#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define INF 999999999;

ll n, m, arr[9], visited[9];

void bt(ll depth, ll num){
    if (depth == m){
        for (ll i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (ll i = num; i <= n; i++){
        visited[i] = 1;
        arr[depth] = i;
        bt(depth + 1, i);
        visited[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    bt(0, 1);

    return 0;
}
