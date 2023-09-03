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
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int b = 0;
    int m, i;
    cin >> m;
    for (i = 0; i < m; i++){
        string k;
        cin >> k;
        if (k == "add"){
            int n;
            cin >> n;
            b |= (1 << n);
        }
        else if (k == "remove"){
            int n;
            cin >> n;
            b &= ~(1 << n);
        }
        else if (k == "check"){
            int n;
            cin >> n;
            if ((b & (1 << n))) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (k == "toggle"){
            int n;
            cin >> n;
            b ^= (1 << n);
        }
        else if (k == "all"){
            b = (1 << 21) - 1;
        }
        else if (k == "empty"){
            b = 0;
        }
    }

    return 0;
}
