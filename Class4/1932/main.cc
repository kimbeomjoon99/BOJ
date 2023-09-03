#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define INF 999999999;

ll arr[500][500], n, ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j <= i; j++) cin >> arr[i][j];
    }

    for (ll i = n - 1; i >= 0; i--){
        for (ll j = 0; j < i; j++)
            arr[i - 1][j] += max(arr[i][j], arr[i][j + 1]);
    }

    cout << arr[0][0] << "\n";

    return 0;
}
