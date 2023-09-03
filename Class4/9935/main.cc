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
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s, bomb;
    cin >> s;
    cin >> bomb;
    int i, j;
    int len = s.size();
    deque<char> arr;
    for (i = 0; i < len; i++){
        arr.push_back(s[i]);
        if (arr.size() < bomb.size()) continue;
        int flag = 0;
        for (j = 0; j < bomb.size(); j++){
            if (arr[arr.size() - bomb.size() + j] != bomb[j]){
                flag++;
                break;
            }
        }
        if (!flag){
            for (j = 0; j < bomb.size(); j++)
                arr.pop_back();
        }
    }
    if (!arr.size()) cout << "FRULA\n";
    else{
        for (i = 0; i < arr.size(); i++)
            cout << arr[i];
        cout << "\n";
    }

    return 0;
}
