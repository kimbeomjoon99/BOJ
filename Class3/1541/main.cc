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
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    string s;
    cin >> s;
    ll i, ans = 0;
    string k = "";
    ll flag = 0;
    for (i = 0; i < s.length(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            k += s[i];
        }
        else if (!flag && s[i] == '+'){
            ans += stoll(k);
            k = "";
        }
        else if (!flag && s[i] == '-'){
            flag++;
            ans += stoll(k);
            k = "";
        }
        else if (flag && s[i] == '+'){
            ans -= stoll(k);
            k = "";
        }
        else if (flag && s[i] == '-'){
            ans -= stoll(k);
            k = "";
        }
    }
    if (flag) ans -= stoll(k);
    else ans += stoll(k);
    cout << ans << "\n";

    return 0;
}
