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
ll land[500][500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, b, i, j, k;
    cin >> n >> m >> b;
    ll Min = 257, Max = -1;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            cin >> land[i][j];
            if (Min > land[i][j]) Min = land[i][j];
            if (Max < land[i][j]) Max = land[i][j];
        }
    }

    pair<ll, ll> ans = {999999999, 0};
    for (i = Min; i <= Max; i++){
        ll crafted = 0, build = 0, possible = b;
        for (j = 0; j < n; j++){
            for (k = 0; k < m; k++){
                possible += land[j][k] - i;
                if (land[j][k] - i > 0){
                    crafted += land[j][k] - i;
                }
                else if (land[j][k] - i < 0){
                    build += -(land[j][k] - i);
                }
            }
        }
        if (possible < 0){
            break;
        }
        ll t = (crafted * 2) + build;
        if (t >= 0 && t <= ans.first){
            ans.first = t;
            ans.second = i;
        }
    }
    cout << ans.first << " " << ans.second << "\n";

    return 0;
}
