#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define INF 999999999;

ll n, m, checker[10001];
vector<ll> arr, nums;

void bt(ll depth, ll num){
    if (depth == m){
        for (ll i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (ll i = num; i < nums.size(); i++){
        arr.push_back(nums[i]);
        bt(depth + 1, i);
        arr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    for (ll i = 0; i < n; i++){
        ll tmp;
        cin >> tmp;
        if (!checker[tmp]){
            nums.push_back(tmp);
            checker[tmp]++;
        }
    }
    sort(nums.begin(), nums.end());
    bt(0, 0);

    return 0;
}
