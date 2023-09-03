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
typedef int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll t, i, j, l;
    cin >> t;
    for (i = 0; i < t; i++){
        priority_queue<ll> max_pq;
        priority_queue<ll, vector<ll>, greater<ll>> min_pq;
        map<ll, ll> m;
        ll k, s = 0;
        cin >> k;
        for (j = 0; j < k; j++){
            char command;
            ll n;
            cin >> command >> n;
            if (command == 'D' && s){
                if (n == 1){
                    while (!m.count(max_pq.top()) || !m[max_pq.top()]){
                        max_pq.pop();
                    }
                    m[max_pq.top()]--;
                    max_pq.pop();
                }
                else if (n == -1){
                    while (!m.count(min_pq.top()) || !m[min_pq.top()]){
                        min_pq.pop();
                    }
                    m[min_pq.top()]--;
                    min_pq.pop();
                }
                s--;
            }
            else if (command == 'I'){
                max_pq.push(n);
                min_pq.push(n);
                if (!m.count(n)) m[n] = 1;
                else m[n]++;
                s++;
            }
        }
        if (!s) cout << "EMPTY\n";
        else {
            while(!m[max_pq.top()]){
                max_pq.pop();
            }
            while(!m[min_pq.top()]){
                min_pq.pop();
            }
            cout << max_pq.top() << " " << min_pq.top() << "\n";
        }
    }

    return 0;
}
