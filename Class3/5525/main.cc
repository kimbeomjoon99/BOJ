#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, i;
    cin >> n;
    cin >> m;
    string s;
    cin >> s;
    ll ans = 0;
    for (i = 0; i < m; i++){
        if (s[i] == 'O') continue;
        ll count = 0;
        while(s[i + 1] == 'O' && s[i + 2] == 'I'){
            count++;
            if (count == n){
                count--;
                ans++;
            }
            i += 2;
        }
    }
    cout << ans << "\n";

    return 0;
}
