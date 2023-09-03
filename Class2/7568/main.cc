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
    
    ll n, i, j;
    cin >> n;
    vector<pair<ll, ll>> arr; // weight, height
    vector<ll> rank;
    for (i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    for (i = 0; i < n; i++){
        ll p = 1;
        for (j = 0; j < n; j++){
            if (i == j) continue;
            if (arr[j].first > arr[i].first && arr[j].second > arr[i].second){
                p++;
            }
        }
        rank.push_back(p);
    }
    for (i = 0; i < n; i++){
        cout << rank[i] << " ";
    }
    cout << "\n";

    return 0;
}
