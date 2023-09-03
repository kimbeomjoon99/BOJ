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
typedef long long ll;
using namespace std;
typedef struct List{
    struct List* parent;
    vector<struct List*> sibling;
    ll num;
}List;
ll visited[101];

ll dfs(List* element){
    if (visited[element->num]) return 0;
    visited[element->num]++;
    if (element->sibling.empty()){
        return 1;
    }
    ll k = 0;
    for (ll i = 0; i < element->sibling.size(); i++){
        k += dfs(element->sibling[i]);
    }
    return k + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, m, i;
    cin >> n;
    cin >> m;
    vector<List*> arr;
    arr.push_back(nullptr);
    for (i = 1; i <= n; i++){
        List* tmp = new List[1];
        tmp->num = i;
        arr.push_back(tmp);
    }
    for (i = 1; i <= m; i++){
        ll a, b;
        cin >> a >> b;
        arr[a]->sibling.push_back(arr[b]);
        arr[b]->sibling.push_back(arr[a]);
    }
    cout << dfs(arr[1]) - 1 << "\n";

    return 0;
}
