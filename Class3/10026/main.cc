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
char rgb[100][100];
char RGB[100][100];
ll visited[100][100];
ll Visited[100][100];
ll n, ans_1, ans_2;

ll dfs_1(ll y, ll x){
    if (visited[y][x]) return 0;
    visited[y][x]++;
    if (y != n - 1 && !visited[y + 1][x] && rgb[y][x] == rgb[y + 1][x])
        dfs_1(y + 1, x);
    if (x != n - 1 && !visited[y][x + 1] && rgb[y][x] == rgb[y][x + 1])
        dfs_1(y, x + 1);
    if (y && !visited[y - 1][x] && rgb[y][x] == rgb[y - 1][x])
        dfs_1(y - 1, x);
    if (x && !visited[y][x - 1] && rgb[y][x] == rgb[y][x - 1])
        dfs_1(y, x - 1);
    return 1; 
}

ll dfs_2(ll y, ll x){
    if (Visited[y][x]) return 0;
    Visited[y][x]++;
    if (y != n - 1 && !Visited[y + 1][x] && RGB[y][x] == RGB[y + 1][x])
        dfs_2(y + 1, x);
    if (x != n - 1 && !Visited[y][x + 1] && RGB[y][x] == RGB[y][x + 1])
        dfs_2(y, x + 1);
    if (y && !Visited[y - 1][x] && RGB[y][x] == RGB[y - 1][x])
        dfs_2(y - 1, x);
    if (x && !Visited[y][x - 1] && RGB[y][x] == RGB[y][x - 1])
        dfs_2(y, x - 1);
    return 1; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll i, j;
    cin >> n;
    for (i = 0; i < n; i++){
        string s;
        cin >> s;
        for (j = 0; j < n; j++){
            rgb[i][j] = s[j];
            RGB[i][j] = rgb[i][j];
            if (RGB[i][j] == 'G') RGB[i][j] = 'R';
        }
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
            ans_1 += dfs_1(i, j);
            ans_2 += dfs_2(i, j);
        }

    cout << ans_1 << " " << ans_2 << "\n";

    return 0;
}
