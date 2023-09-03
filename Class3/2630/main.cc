#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

vector<vector<int>> map;
pair<int, int> div(int, int, int, int);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    int i, j;
    
    for (i = 0; i < n; i++){
        vector<int> tmp;
        for (j = 0; j < n; j++){
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        map.push_back(tmp);
    }

    pair<int, int> ans = div(map[0][0], n, 0, 0);

    cout << ans.first << "\n";
    cout << ans.second << "\n";

    return 0;
}

pair<int, int> div(int key, int size, int n, int m){
    if (size == 1){
        if (!key){
            return make_pair(1, 0);
        }
        else return make_pair(0, 1);
    }
    int i, j;
    int div_flag = 0;
    for (i = n; i < n + size; i++){
        int flag = 0;
        for (j = m; j < m + size; j++){
            if (map[i][j] != key){
                flag++;
                break;
            }
        }
        if (flag){
            div_flag++;
            break;
        }
    }

    if (div_flag){
        pair<int, int> a = div(map[n][m], size / 2, n, m);
        pair<int, int> b = div(map[n + (size / 2)][m + (size / 2)], size / 2, n + (size / 2), m + (size / 2));
        pair<int, int> c = div(map[n][m + (size / 2)], size / 2, n, m + (size / 2));
        pair<int, int> d = div(map[n + (size / 2)][m], size / 2, n + (size / 2), m);
        pair<int, int> p = make_pair(a.first + b.first + c.first + d.first, a.second + b.second + c.second + d.second);
        return p;
    }
    else{
        if (!key){
            return make_pair(1, 0);
        }
        else return make_pair(0, 1);
    }
}
