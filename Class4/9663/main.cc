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

int board[15];
int n, cnt = 0;

void bt(int depth){
    if (depth == n){
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++){
        board[depth] = i;
        int flag = 0;
        for (int j = 0; j < depth; j++){
            int k = abs(board[depth] - board[j]);
            if (board[depth] == board[j] || depth - j == k){
                flag++;
                break;
            }
        }
        if (!flag) bt(depth + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    bt(0);
    cout << cnt << "\n";

    return 0;
}
