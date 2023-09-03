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
    
    ll n, i, j;
    cin >> n;
    queue<ll> q;
    for (i = 1; i <= n; i++){
        q.push(i);
    }
    for (i = 1; i < n; i++){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    //q.pop();
    cout << q.front() << "\n";
    
    return 0;
}
