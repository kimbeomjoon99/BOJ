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
ll arr[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    vector<string> s;
    vector<string> ans;
    ll cnt = 0;
    ll i, j;
    while(1){
        string k;
        getline(cin, k);
        if (k == ".") break;
        s.push_back(k);
        cnt++;
    }

    for (i = 0; i < cnt; i++){
        stack<ll> st;
        ll flag = 0;
        for (j = 0; j < s[i].length(); j++){
            if (s[i][j] == '('){
                st.push(s[i][j]);
            }
            else if (s[i][j] == '['){
                st.push(s[i][j]);
            }
            else if (s[i][j] == ')'){
                if (st.empty()) {
                    flag++;
                    break;
                }
                else if (st.top() != '('){
                    flag++;
                    break;
                }
                else st.pop();
            }
            else if (s[i][j] == ']'){
                if (st.empty()) {
                    flag++;
                    break;
                }
                else if (st.top() != '['){
                    flag++;
                    break;
                }
                else st.pop();
            }
        }
        if (!st.empty()) ans.push_back("no");
        else if (flag) ans.push_back("no");
        else ans.push_back("yes");
    }

    for (i = 0; i < cnt; i++){
        cout << ans[i] << "\n";
    }
    
    
    return 0;
}
