#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
long long n, m;
vector<long long> arr;
long long segtree[4000000];

void makesegtree(long long node, long long st, long long ed) {
    if (st == ed) {
        segtree[node] = arr[st];
        return;
    }
    else {
        long long middle = (st + ed) / 2;
        segtree[node] = 0;
        makesegtree(node * 2, st, middle);
        makesegtree((node * 2) + 1, middle + 1, ed);
        //long long left = segtree[node * 2];
        //long long right = segtree[(node * 2) + 1];
        return;
    }
}

long long update(long long node, long long st, long long ed, long long left, long long right, long long ud) {
    if (right < st || ed < left) return segtree[node];
    else if (left <= st && right >= ed) {
        segtree[node] += ud;
        return segtree[node];
    }
    else {
        long long middle = (st + ed) / 2;
        long long a = update(node * 2, st, middle, left, right, ud);
        long long b = update((node * 2) + 1, middle + 1, ed, left, right, ud);
        //segtree[node] = a + b;
        return segtree[node];
    }
}

long long query(long long node, long long st, long long ed, long long find, long long ans) {
    if (st > find || ed < find) {
        return 0;
    }
    else if (st == ed) {
        ans += segtree[node];
        return ans;
    }
    else {
        ans += segtree[node];
        long long middle = (st + ed) / 2;
        long long a = query(node * 2, st, middle, find, ans);
        long long b = query((node * 2) + 1, middle + 1, ed, find, ans);
        return a + b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    long long i, j;
    arr.push_back(0);
    for (i = 0; i < n; i++) {
        long long a;
        cin >> a;
        arr.push_back(a);
    }
    makesegtree(1, 1, n);

    cin >> m;

    for (i = 0; i < m; i++) {
        long long p, a, b, k, x;
        cin >> p;
        if (p == 1) {
            cin >> a >> b >> k;
            update(1, 1, n, a, b, k);
        }
        else if (p == 2) {
            cin >> x;
            long long ans = query(1, 1, n, x, 0);
            cout << ans << "\n";
        }
    }

    return 0;
}
