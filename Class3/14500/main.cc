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
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m, i, j;
    cin >> n >> m;
    vector<vector<int>> table;
    for (i = 0; i < n + 6; i++){
        vector<int> r;
        if (i < 3 || i > n + 2){
            for (j = 0; j < m + 6; j++)
                r.push_back(0);
            table.push_back(r);
            continue;
        }
        for (j = 0; j < m + 6; j++){
            if (j < 3 || j > m + 2){
                r.push_back(0);
                continue;
            }
            int tmp;
            cin >> tmp;
            r.push_back(tmp);
        }
        table.push_back(r);
    }
    int ans = 0;
    for (i = 3; i < n + 3; i++){
        for (j = 3; j < m + 3; j++){
            int a = table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i + 3][j];
            int b = table[i][j] + table[i][j + 1] + table[i][j + 2] + table[i][j + 3]; // type 1
            int c = table[i][j] + table[i + 1][j] + table[i][j + 1] + table[i + 1][j + 1]; // type 2
            int d = table[i][j] + table[i][j + 1] + table[i][j + 2] + table[i - 1][j + 1];
            int e = table[i][j] + table[i][j + 1] + table[i][j + 2] + table[i + 1][j + 1];
            int f = table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i + 1][j - 1];
            int g = table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i + 1][j + 1]; // type 3
            int h = table[i][j] + table[i + 1][j] + table[i + 1][j - 1] + table[i + 2][j - 1];
            int k = table[i][j] + table[i + 1][j] + table[i + 1][j + 1] + table[i + 2][j + 1];
            int l = table[i][j] + table[i][j + 1] + table[i - 1][j + 1] + table[i - 1][j + 2];
            int o = table[i][j] + table[i][j + 1] + table[i + 1][j + 1] + table[i + 1][j + 2]; // type 4
            int p = table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i + 2][j - 1];
            int q = table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i + 2][j + 1];
            int s = table[i][j] + table[i][j + 1] + table[i][j + 2] + table[i - 1][j + 2];
            int t = table[i][j] + table[i][j + 1] + table[i][j + 2] + table[i + 1][j + 2];
            int u = table[i][j] + table[i][j + 1] + table[i][j + 2] + table[i - 1][j];
            int v = table[i][j] + table[i][j + 1] + table[i][j + 2] + table[i + 1][j];
            int w = table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i][j - 1];
            int x = table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i][j + 1];
            int y = table[i][j] + table[i][j - 1] + table[i + 1][j - 1] + table[i + 2][j - 1];
            int z = table[i][j] + table[i][j + 1] + table[i + 1][j + 1] + table[i + 2][j + 1];
            int aa = table[i][j] + table[i - 1][j] + table[i - 1][j + 1] + table[i - 1][j + 2];
            int ab = table[i][j] + table[i + 1][j] + table[i + 1][j + 1] + table[i + 1][j + 2]; // type 5
            ans = max({ans, a, b, c, d, e, f, g, h, k, l, o, p, q, s, t, u, v, w, x});
        }
    }
    cout << ans << "\n";

    return 0;
}
