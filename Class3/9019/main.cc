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
using namespace std;
typedef int ll;
typedef pair<int, string> pi;
int vtable[10000];

void clr(){
    for (int i = 0; i < 10000; i++)
        vtable[i] = 0;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    clr();
    int n, i, j;
    cin >> n;
    vector<string> ans;
    for (i = 0; i < n; i++){
        deque<pi> reg;
        pi op;
        int init, end;
        cin >> init >> end;
        if (init == end){
            ans.push_back("");
            continue;
        }
        reg.push_back({init, ""});
        vtable[init]++;
        while(1){
            if (reg.front().first == end){
                op = reg.front();
            }
            pi d = reg.front();
            pi s = d, l = d, r = d;
            d.first = (d.first * 2) % 10000;
            if (!vtable[d.first]){
                d.second += "D";
                if (d.first == end){
                    op = d;
                    break;
                }
                vtable[d.first]++;
                reg.push_back(d);
            }

            s.first--;
            if (s.first < 0) s.first = 9999;
            if (!vtable[s.first]){
                s.second += "S";
                if (s.first == end){
                    op = s;
                    break;
                }
                vtable[s.first]++;
                reg.push_back(s);
            }

            l.first *= 10;
            l.first += l.first / 10000;
            l.first %= 10000;
            if (!vtable[l.first]){
                l.second += "L";
                if (l.first == end){
                    op = l;
                    break;
                }
                vtable[l.first]++;
                reg.push_back(l);
            }
            
            int tmp = r.first % 10;
            r.first /= 10;
            r.first += tmp * 1000;
            if (!vtable[r.first]){
                r.second += "R";
                if (r.first == end){
                    op = r;
                    break;
                }
                vtable[r.first]++;
                reg.push_back(r);
            }

            reg.pop_front();
        }
        clr();
        ans.push_back(op.second);
    }
    for (i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
