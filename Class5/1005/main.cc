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

typedef struct vertex{
    ll pre;
    vector<struct vertex*> suc;
    vector<ll> pre_cost;
    ll index;
    ll cost;
    //ll total;
}vertex;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll t, i, j, l;
    cin >> t;
    for (i = 0; i < t; i++){
        ll n, k;
        cin >> n >> k;
        vector<vertex*> vertice;
        vector<int> used;
        vertice.push_back(nullptr);
        used.push_back(1);
        vector<pair<ll, ll>> order;
        order.push_back({0, 0});
        for (j = 0; j < n; j++){
            vertex* a = new vertex[1];
            ll c;
            cin >> c;
            a->cost = c;
            //a->total = c;
            a->index = j + 1;
            a->pre_cost.push_back(0);
            a->pre = 0;
            vertice.push_back(a);
            used.push_back(0);
        }
        for (j = 0; j < k; j++){
            ll a, b;
            cin >> a >> b;
            order.push_back({a, b});
        }
        sort(order.begin(), order.end());
        ll goal;
        cin >> goal;

        for (j = 1; j <= k; j++){
            vertice[order[j].first]->suc.push_back(vertice[order[j].second]);
            vertice[order[j].second]->pre++;
        }
        
        queue<vertex*> q;
        while (1){
            for (j = 1; j <= n; j++){
                if (!used[j] && !vertice[j]->pre){
                    q.push(vertice[j]);
                    used[j] = 1;
                }
            }
            
            q.front()->cost += *max_element(q.front()->pre_cost.begin(), q.front()->pre_cost.end());
            for (l = 0; l < q.front()->suc.size(); l++){
                q.front()->suc[l]->pre_cost.push_back(q.front()->cost);
                q.front()->suc[l]->pre--;
            }

            //cout << q.front()->cost << "\n";
            
            if (q.front()->index == goal){
                break;
            }
            q.pop();
        }

        cout << q.front()->cost << "\n";
        for (j = 1; j <= n; j++){
            delete[] vertice[j];
        }
    }

    return 0;
}
