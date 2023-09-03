#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio;
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    vector<pair<int, string>> w;

    int i, j;
    int total = 0;
    for (i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        int c_flag = 0;
        if (i) {
            for (j = 0; j < total; j++) {
                if (tmp == w[j].second) {
                    c_flag++;
                    break;
                }
            }
        }
        if (c_flag) continue;
        int l = tmp.length();
        w.push_back(make_pair(l, tmp));
        total++;
    }

    sort(w.begin(), w.end());

    for (i = 0; i < total; i++) {
        cout << w[i].second << "\n";
    }

    return 0;
}
