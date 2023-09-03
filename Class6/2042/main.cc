#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
long long n, m, k;
vector<long long> arr;
long long segtree[4000000];

void makesegtree(long long node, long long st, long long ed) {
    if (st == ed) {
        segtree[node] = arr[st];
        return;
    }
    else {
        long long middle = (st + ed) / 2;
        makesegtree(node * 2, st, middle);
        makesegtree((node * 2) + 1, middle + 1, ed);
        long long left = segtree[node * 2];
        long long right = segtree[(node * 2) + 1];
        segtree[node] = left + right;
        return;
    }
}

long long update(long long node, long long st, long long ed, long long ind, long long ud){
    if (ind < st || ed < ind) return segtree[node];
    else if (st == ed){
        segtree[node] = ud;
        return segtree[node];
    }
    else{
        long long middle = (st + ed) / 2;
        long long a = update(node * 2, st, middle, ind, ud);
        long long b = update((node * 2) + 1, middle + 1, ed, ind, ud);
        segtree[node] = a + b;
        return segtree[node];
    }
}

long long query(long long node, long long st, long long ed, long long left, long long right){
    if (st >= left && ed <= right){
        return segtree[node];
    }
    else if (st > right || ed < left){
        return 0;
    }
    else{
        long long middle = (st + ed) / 2;
        long long a = query(node * 2, st, middle, left, right);
        long long b = query((node * 2) + 1, middle + 1, ed, left, right);
        return a + b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    long long i;
    for (i = 0; i < n; i++) {
        long long a;
        cin >> a;
        arr.push_back(a);
    }
    makesegtree(1, 0, n - 1);

    for (i = 0; i < m + k; i++){
        long long command, a, b;
        cin >> command >> a >> b;
        if (command == 1){
            update(1, 1, n, a, b);
        }
        else if (command == 2){
            long long p = query(1, 1, n, a, b);
            cout << p << "\n";
        }
    }

    return 0;
}
