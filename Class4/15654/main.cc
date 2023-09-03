#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define INF 999999999;

ll n, m, visited[9];
vector<ll> arr, nums;

void bt(ll depth){
    if (depth == m){
        for (ll i = 0; i < arr.size(); i++)
            cout <<  arr[i] << " ";
        cout << "\n";
        return;
    }
    for (ll i = 0; i < n; i++){
        if (visited[i]) continue;
        visited[i] = 1;
        arr.push_back(nums[i]);
        bt(depth + 1);
        arr.pop_back();
        visited[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    for (ll i = 0; i < n; i++){
        ll tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());
    bt(0);

    return 0;
}
