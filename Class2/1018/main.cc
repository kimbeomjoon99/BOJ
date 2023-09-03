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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll m, n, i, j;
    cin >> n >> m;
    vector<string> board;
    for (i = 0; i < n; i++){
        string a;
        cin >> a;
        board.push_back(a);
    }
    ll ans = 100;
    for (ll l = 0; l <= n - 8; l++){
        for (ll o = 0; o <= m - 8; o++){  
            ll ans_a = 0, ans_b = 0;
            for (i = 0 + l; i < 8 + l; i++){
                for (j = 0 + o; j < o + 8; j++){
                    if (!(i % 2) && !(j % 2)){
                        if (board[i][j] != 'W') ans_a++;
                    }
                    else if ((i % 2) && !(j % 2)){
                        if (board[i][j] != 'B') ans_a++;
                    }
                    else if (!(i % 2) && (j % 2)){
                        if (board[i][j] != 'B') ans_a++;
                    }
                    else if (i % 2 && j % 2){
                        if (board[i][j] != 'W') ans_a++;
                    }
                }
            }
            for (i = 0 + l; i < 8 + l; i++){
                for (j = 0 + o; j < o + 8; j++){
                    if (!(i % 2) && !(j % 2)){
                        if (board[i][j] != 'B') ans_b++;
                    }
                    else if ((i % 2) && !(j % 2)){
                        if (board[i][j] != 'W') ans_b++;
                    }
                    else if (!(i % 2) && (j % 2)){
                        if (board[i][j] != 'W') ans_b++;
                    }
                    else if (i % 2 && j % 2){
                        if (board[i][j] != 'B') ans_b++;
                    }
                }
            }
            ll tmp = min(ans_a, ans_b);
            ans = min(ans, tmp);
        }
    }
    cout << ans << "\n";

    return 0;
}
