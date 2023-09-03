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
    
    ll t, i;
    cin >> t;
    for (i = 0; i < t; i++){
        deque<pair<ll, ll>> q;
        vector<ll> p;
        ll n, m, j;
        cin >> n >> m;
        for (j = 0; j < n; j++){
            ll prior;
            cin >> prior;
            p.push_back(prior);
            q.push_front({prior, j});
        }
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        ll ind = 0, num = 1;
        while(!q.empty()){
            if (q.back().first != p[ind]){
                q.push_front(q.back());
                q.pop_back();
            }
            else{
                if (q.back().second == m){
                    cout << num << "\n";
                    break;
                }
                else{
                    q.pop_back();
                    num++;
                }
                ind++;
            }
        }
    }
    
    return 0;
}
