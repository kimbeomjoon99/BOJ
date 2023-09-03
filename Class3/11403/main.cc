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
#define inf 999999999;
ll visited[100][100];
ll G[100][100];
ll ans[100][100];
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll i, j, k;
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                if (G[j][i] && G[i][k]) G[j][k] = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << G[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
