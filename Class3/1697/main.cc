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
typedef int ll;
using namespace std;
ll visited[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, k;
    cin >> n >> k;
    if (n == k){
        cout << 0 << "\n";
        return 0;
    }
    queue<ll> q;
    q.push(n);
    ll ans = 0;
    ll l = 1;
    while(1){
        ll flag = 0;
        ll s = q.size();
        for (ll i = 0; i < s; i++){
            if (q.front() == k){
                flag++;
                break;
            }
            if (q.front() * 2 <= 100000 && !visited[q.front() * 2]){
                q.push(q.front() * 2);
                visited[q.front() * 2]++;
            }
            if (q.front() != 100000 && !visited[q.front() + 1]){
                q.push(q.front() + 1);
                visited[q.front() + 1]++;
            }
            if (q.front() && !visited[q.front() - 1]){
                q.push(q.front() - 1);
                visited[q.front() - 1]++;
            }
            q.pop();
        }
        if (flag) break;
        ans++;
    }
    
    cout << ans << "\n";

    return 0;
}
