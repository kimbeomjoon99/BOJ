#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

ll a, b, i;

ll bfs(){
    if (a == b) return 0;
    queue<pi> q;
    q.push({a, 1});
    while(!q.empty()){
        pi k = q.front();
        q.pop();
        ll c = k.first * 2;
        if (c == b) return k.second + 1;
        else if (c < b) q.push({c, k.second + 1});
        c = (k.first * 10) + 1;
        if (c == b) return k.second + 1;
        else if (c < b) q.push({c, k.second + 1});
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a >> b;
    cout << bfs() << "\n";
    
    return 0;
}
