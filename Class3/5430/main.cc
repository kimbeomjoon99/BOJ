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
typedef int ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll t, i, j;
    cin >> t;
    for (i = 0; i < t; i++){
        string func, A;
        cin >> func;
        ll arr_size;
        cin >> arr_size;
        cin >> A;
        deque<ll> arr;
        ll ind = 1;
        for (j = 0; j < arr_size; j++){
            stack<ll> tmp;
            tmp.push(A[ind] - 48);
            ind++;
            while(1){
                if (A[ind] == ',' || A[ind] == ']') break;
                tmp.push(A[ind] - 48);
                ind++;
            }
            ind++;
            ll ele = 0;
            ll p = 1;
            while(!tmp.empty()){
                ele += tmp.top() * p;
                tmp.pop();
                p *= 10;
            }
            arr.push_front(ele);
        }
        bool position_flag = true;
        ll empty_flag = 0;
        for (j = 0; j < func.length(); j++){
            if (func[j] == 'R'){
                if (position_flag) position_flag = false;
                else position_flag = true;
            }
            else if (func[j] == 'D'){
                if (arr.empty()){
                    empty_flag++;
                    break;
                }
                else if (position_flag){
                    arr.pop_back();
                }
                else if (!position_flag){
                    arr.pop_front();
                }
            }
        }
        if (empty_flag) cout << "error";
        else{
            cout << "[";
            if (arr.empty()) cout << "]";
            while(!arr.empty()){
                if (position_flag){
                    cout << arr.back();
                    arr.pop_back();
                }
                else {
                    cout << arr.front();
                    arr.pop_front();
                }
                if (arr.empty()) cout << "]";
                else cout << ",";
            }
        }
        cout << "\n";
    }

    return 0;
}
