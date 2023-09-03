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
ll nums[8001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, i, j;
    ll sum = 0;
    cin >> n;
    vector<ll> arr;
    priority_queue<pair<ll, ll>> pq;
    for (i = 0; i < n; i++){
        ll a;
        cin >> a;
        sum += a;
        arr.push_back(a);
        nums[a + 4000]++;
    }
    for (i = 0; i <= 8000; i++){
        if (nums[i]){
            if (pq.empty())
                pq.push({nums[i], -(i - 4000)});
            else if (pq.top().first < nums[i]){
                pq = priority_queue<pair<ll, ll>>();
                pq.push({nums[i], -(i - 4000)});
            }
            else if (pq.top().first == nums[i])
                pq.push({nums[i], -(i - 4000)});
        }
    }
    ll most;
    if (pq.size() == 1){
        most = -pq.top().second;
    }
    else {
        pq.pop();
        most = -pq.top().second;
    }
    sort(arr.begin(), arr.end());
    ll avr = (ll)(round((double)sum / n));
    cout << avr << "\n";
    cout << arr[(n - 1) / 2] << "\n";
    cout << most << "\n";
    cout << arr[n - 1] - arr[0] << "\n";
    
    return 0;
}
