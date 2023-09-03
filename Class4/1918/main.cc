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
typedef pair<int, int> pi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string postfix;
    cin >> postfix;
    stack<char> s;
    for (int i = 0; i < postfix.size(); i++){
        if ((int)postfix[i] >= 65 && (int)postfix[i] <= 90)
            cout << postfix[i];
        else if (postfix[i] == '(') s.push(postfix[i]);
        else if (postfix[i] == ')'){
            while(s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if (postfix[i] == '*' || postfix[i] == '/'){
            if (s.empty()){
                s.push(postfix[i]);
                continue;
            }
            if (s.top() == '('){
                s.push(postfix[i]);
                continue;
            }
            if (s.top() == '*' || s.top() == '/'){
                while(s.top() == '*' || s.top() == '/'){
                    cout << s.top();
                    s.pop();
                    if (s.empty() || s.top() == '(') break;
                }
            }
            s.push(postfix[i]);
        }
        else if (postfix[i] == '+' || postfix[i] == '-'){
            if (s.empty()){
                s.push(postfix[i]);
                continue;
            }
            if (s.top() == '('){
                s.push(postfix[i]);
                continue;
            }
            while(!s.empty()){
                if (s.top() == '(') break;
                cout << s.top();
                s.pop();
            }
            s.push(postfix[i]);
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << "\n";

    return 0;
}
