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
ll score[301];
ll dp[301];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, i;
    cin >> n;
    for (i = 1; i <= n; i++){
        cin >> score[i];
    }
    dp[1] = score[1];
    dp[2] = dp[1] + score[2];
    dp[3] = max(score[2] + score[3], dp[1] + score[3]);
    for (i = 4; i <= n; i++){
        dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
    }

    cout << dp[n] << "\n";

    return 0;
}
