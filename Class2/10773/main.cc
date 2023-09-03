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
    
    ll n, i;
    cin >> n;
    stack<ll> st;
    for (i = 0; i < n; i++){
        ll num;
        cin >> num;
        if (!num){
            st.pop();
        }
        else st.push(num);
    }
    ll ans = 0;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout << ans << "\n";
    
    return 0;
}
