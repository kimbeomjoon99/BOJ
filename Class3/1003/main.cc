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
int dp[41];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t, i;
    dp[1] = 1;
    for (i = 2; i <= 40; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if (!n) cout << 1 << " " << 0 << "\n";
        else cout << dp[n - 1] << " " << dp[n] << "\n";
    }

    return 0;
}
