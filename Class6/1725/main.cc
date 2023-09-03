#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll n, i, j;
    cin >> n;
    vector<ll> histogram;
    stack<ll> s;
    histogram.push_back(0);
    s.push(0);
    for (i = 0; i < n; i++){
        ll a;
        cin >> a;
        histogram.push_back(a);
    }

    ll ans = 0;
    //cout << ans << "\n";
    for (i = 1; i <= n + 1; i++){
        if (i == 1){
            s.push(i);
        }
        else if (histogram[s.top()] > histogram[i]){
            while(!s.empty() && (histogram[s.top()] > histogram[i])){
                ll height = s.top();
                s.pop();
                ll r = histogram[height] * (i - s.top() - 1);
                if (r > ans) ans = r;
            }
            s.push(i);
        }
        else{
            s.push(i);
        }
    }
    
    cout << ans << "\n";

    return 0;
}
