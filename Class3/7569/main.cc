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
ll box[100][100][100]; // h, y, x
ll visited[100][100][100];
ll h, y, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll i, j, k;
    cin >> x >> y >> h;
    tuple<ll, ll, ll> f;
    queue<tuple<ll, ll, ll>> q;
    ll f_flag = 0, flag = 0;
    for (i = 0; i < h; i++)
        for (j = 0; j < y; j++)
            for (k = 0; k < x; k++){
                cin >> box[i][j][k];
                if (box[i][j][k] == 1){
                    visited[i][j][k] = 1;
                    f = {i, j, k};
                    q.push(f);
                    f_flag++;
                }
                if (box[i][j][k] == -1) visited[i][j][k] = 1;
                if (!box[i][j][k]) flag++;
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
            ll a = get<0>(q.front());
            ll b = get<1>(q.front());
            ll c = get<2>(q.front());
            if (a != h - 1 && !visited[a + 1][b][c] && !box[a + 1][b][c]){
                q.push({a + 1, b, c});
                visited[a + 1][b][c]++;
                box[a + 1][b][c] = 1;
            }
            if (b != y - 1 && !visited[a][b + 1][c] && !box[a][b + 1][c]){
                q.push({a, b + 1, c});
                visited[a][b + 1][c]++;
                box[a][b + 1][c] = 1;
            }
            if (c != x - 1 && !visited[a][b][c + 1] && !box[a][b][c + 1]){
                q.push({a, b, c + 1});
                visited[a][b][c + 1]++;
                box[a][b][c + 1] = 1;
            }
            if (a && !visited[a - 1][b][c] && !box[a - 1][b][c]){
                q.push({a - 1, b, c});
                visited[a - 1][b][c]++;
                box[a - 1][b][c] = 1;
            }
            if (b && !visited[a][b - 1][c] && !box[a][b - 1][c]){
                q.push({a, b - 1, c});
                visited[a][b - 1][c]++;
                box[a][b - 1][c] = 1;
            }
            if (c && !visited[a][b][c - 1] && !box[a][b][c - 1]){
                q.push({a, b, c - 1});
                visited[a][b][c - 1]++;
                box[a][b][c - 1] = 1;
            }
            q.pop();
        }
    }

    for (i = 0; i < h; i++)
        for (j = 0; j < y; j++)
            for (k = 0; k < x; k++){
                if (!visited[i][j][k]) ans = -1;
            }


    cout << ans << "\n";
    return 0;
}
