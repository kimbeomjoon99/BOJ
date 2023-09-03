#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n, i;
    deque<ll> s;
    cin >> n;
    for (i = 0; i < n; i++){
        string k;
        cin >> k;
        if (k == "push_front"){
            ll num;
            cin >> num;
            s.push_front(num);
        }
        else if (k == "push_back"){
            ll num;
            cin >> num;
            s.push_back(num);
        }
        else if (k == "pop_front"){
            if (s.empty()) cout << -1 << "\n";
            else {
                cout << s.front() << "\n";
                s.pop_front();
            }
        }
        else if (k == "pop_back"){
            if (s.empty()) cout << -1 << "\n";
            else {
                cout << s.back() << "\n";
                s.pop_back();
            }
        }
        else if (k == "size"){
            cout << s.size() << "\n";
        }
        else if (k == "empty"){
            if (s.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (k == "front"){
            if (s.empty()) cout << -1 << "\n";
            else cout << s.front() << "\n";
        }
        else if (k == "back"){
            if (s.empty()) cout << -1 << "\n";
            else cout << s.back() << "\n";
        }
    }
    
    return 0;
}
