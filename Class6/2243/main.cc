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
long long segtree[5000000];

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

void update(long long node, long long st, long long ed, long long ind, long long ud) {
    if (ind < st || ed < ind) return;
    else if (st == ed) {
        segtree[node] += ud;
        return;
    }
    else {
        segtree[node] += ud;
        long long middle = (st + ed) / 2;
        update(node * 2, st, middle, ind, ud);
        update((node * 2) + 1, middle + 1, ed, ind, ud);
        return;
    }
}

long long query(long long node, long long st, long long ed, long long find) {
    if (st == ed) return st;
    else {
        long long middle = (st + ed) / 2;
        long long ans;
        if (find <= segtree[node * 2]) {
            ans = query(node * 2, st, middle, find);
        }
        else {
            ans = query((node * 2) + 1, middle + 1, ed, find - segtree[node * 2]);
        }
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    long long i;
    for (i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b;
            long long candy = query(1, 1, 1000000, b);
            cout << candy << "\n";
            update(1, 1, 1000000, candy, -1);
        }
        else if (a == 2) {
            cin >> b >> c;
            update(1, 1, 1000000, b, c);
        }
    }

    return 0;
}
