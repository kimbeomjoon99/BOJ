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
ll box[1000][1000]; // h, y, x
ll visited[1000][1000];
ll y, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll i, j, k;
    cin >> x >> y;
    pair<ll, ll> f;
    queue<pair<ll, ll>> q;
    ll f_flag = 0, flag = 0;
    for (i = 0; i < y; i++)
        for (j = 0; j < x; j++){
            cin >> box[i][j];
            if (box[i][j] == 1){
                visited[i][j] = 1;
                f = {i, j};
                q.push(f);
                f_flag++;
            }
            if (box[i][j] == -1) visited[i][j] = 1;
            if (!box[i][j]) flag++;
        }
    
    if (!flag){
        cout << 0 << "\n";
        return 0;
    }
    ll ans = -1;
    while(!q.empty()){
        ans++;
        ll s = q.size();
        for (i = 0; i < s; i++){
            ll a = q.front().first;
            ll b = q.front().second;
            if (a != y - 1 && !visited[a + 1][b] && !box[a + 1][b]){
                q.push({a + 1, b});
                visited[a + 1][b]++;
                box[a + 1][b] = 1;
            }
            if (b != x - 1 && !visited[a][b + 1] && !box[a][b + 1]){
                q.push({a, b + 1});
                visited[a][b + 1]++;
                box[a][b + 1] = 1;
            }
            if (a && !visited[a - 1][b] && !box[a - 1][b]){
                q.push({a - 1, b});
                visited[a - 1][b]++;
                box[a - 1][b] = 1;
            }
            if (b && !visited[a][b - 1] && !box[a][b - 1]){
                q.push({a, b - 1});
                visited[a][b - 1]++;
                box[a][b - 1] = 1;
            }
            q.pop();
        }
    }

    for (i = 0; i < y; i++)
        for (j = 0; j < x; j++)
            if (!visited[i][j]) ans = -1;


    cout << ans << "\n";
    return 0;
}
