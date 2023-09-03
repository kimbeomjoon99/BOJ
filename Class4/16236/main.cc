#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;  // 상좌우하 bfs

struct cmp{
    bool operator()(pair<pi, ll> a, pair<pi, ll> b){
        if (a.second > b.second) return true;
        else if (a.second < b.second) return false;
        else{
            if (a.first.first > b.first.first) return true;
            else if (a.first.first < b.first.first) return false;
            else if (a.first.second > b.first.second) return true;
            else return false;
        }
    }
};

ll n, arr[20][20], clk = 0, visited[20][20];
pi st;

typedef struct status{
    ll s;
    ll eaten;
}status;

status shark;

ll bfs(){
    priority_queue<pair<pi, ll>, vector<pair<pi, ll>>, cmp> q;
    q.push({st, 0});
    visited[st.first][st.second] = 1;
    ll depth = 0;
    while(!q.empty()){
        pi here = q.top().first;
        ll dist = q.top().second;
        if (arr[here.first][here.second] &&
            arr[here.first][here.second] < shark.s){
            shark.eaten++;
            if (shark.eaten == shark.s){
                shark.s++;
                shark.eaten = 0;
            }
            st = here;
            arr[here.first][here.second] = 0;
            return dist;
        }
        q.pop();
        if (here.first && !visited[here.first - 1][here.second]
            && arr[here.first - 1][here.second] <= shark.s){
            q.push({{here.first - 1, here.second}, dist + 1});
            visited[here.first - 1][here.second] = 1;
        }
        if (here.second && !visited[here.first][here.second - 1]
            && arr[here.first][here.second - 1] <= shark.s){
            q.push({{here.first, here.second - 1}, dist + 1});
            visited[here.first][here.second - 1] = 1;
        }
        if (here.second < n - 1 && !visited[here.first][here.second + 1]
            && arr[here.first][here.second + 1] <= shark.s){
            q.push({{here.first, here.second + 1}, dist + 1});
            visited[here.first][here.second + 1] = 1;
        }
        if (here.first < n - 1 && !visited[here.first + 1][here.second]
            && arr[here.first + 1][here.second] <= shark.s){
            q.push({{here.first + 1, here.second}, dist + 1});
            visited[here.first + 1][here.second] = 1;
        }
    }
    return 0;
}

void Clear(){
    for (ll i = 0; i < 20; i++)
        for (ll j = 0; j < 20; j++)
            visited[i][j] = 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 9){
                st.first = i;
                st.second = j;
                arr[i][j] = 0;
            }
        }
    shark.s = 2;
    shark.eaten = 0;
    while(1){
        ll d = bfs();
        if (!d) break;
        clk += d;
        Clear();
    }
    cout << clk << "\n";
    
    return 0;
}
