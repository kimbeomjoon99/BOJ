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
    
    ll n, i;
    vector<ll> arr;
    stack<ll> s;
    cin >> n;
    for (i = 0; i < n; i++){
        ll a;
        cin >> a;
        arr.push_back(a);
    }
    ll num = 1, ind = 0;
    vector<char> ans;
    while(1){
        while(!s.empty() && s.top() == arr[ind]){
            s.pop();
            ans.push_back('-');
            ind++;
        }
        if (num == n + 1) break;
        s.push(num);
        ans.push_back('+');
        num++;
    }
    
    if (s.empty()){
        for (i = 0; i < ans.size(); i++){
            cout << ans[i] << "\n";
        }
    }
    else cout << "NO" << "\n";
    
    return 0;
}
