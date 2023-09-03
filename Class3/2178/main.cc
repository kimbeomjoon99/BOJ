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
vector<string> maze;
ll visited[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, i;
    cin >> n >> m;
    for (i = 0; i < n; i++){
        string s;
        cin >> s;
        maze.push_back(s);
    }
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    visited[0][0]++;
    ll ans = 0;
    pair<ll, ll> loc = {0, 0};
    while(!q.empty()){
        ll flag = 0;
        ll s = q.size();
        for (i = 0; i < s; i++){
            if (q.front().first == n - 1 && q.front().second == m - 1){
                flag++;
                break;
            }
            if (q.front().first != n - 1 && !visited[q.front().first + 1][q.front().second] && maze[q.front().first + 1][q.front().second] == '1'){
                q.push({q.front().first + 1, q.front().second});
                visited[q.front().first + 1][q.front().second]++;
            }
            if (q.front().second != m - 1 && !visited[q.front().first][q.front().second + 1] && maze[q.front().first][q.front().second + 1] == '1'){
                q.push({q.front().first, q.front().second + 1});
                visited[q.front().first][q.front().second + 1]++;
            }
            if (q.front().first && !visited[q.front().first - 1][q.front().second] && maze[q.front().first - 1][q.front().second] == '1'){
                q.push({q.front().first - 1, q.front().second});
                visited[q.front().first - 1][q.front().second]++;
            }
            if (q.front().second && !visited[q.front().first][q.front().second - 1] && maze[q.front().first][q.front().second - 1] == '1'){
                q.push({q.front().first, q.front().second - 1});
                visited[q.front().first][q.front().second - 1]++;
            }
            q.pop();
        }
        ans++;
        if (flag) break;
    }
    cout << ans << "\n";

    return 0;
}
