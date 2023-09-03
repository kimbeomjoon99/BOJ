#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, char> pii;

ll n;
pii tree[26];

void preorder(ll here){
    cout << char(here + 'A');
    if (tree[here].first != '.')
        preorder(tree[here].first - 'A');
    if (tree[here].second != '.')
        preorder(tree[here].second - 'A');
}

void inorder(ll here){
    if (tree[here].first != '.')
        inorder(tree[here].first - 'A');
    cout << char(here + 'A');
    if (tree[here].second != '.')
        inorder(tree[here].second - 'A');
}

void postorder(ll here){
    if (tree[here].first != '.')
        postorder(tree[here].first - 'A');
    if (tree[here].second != '.')
        postorder(tree[here].second - 'A');
    cout << char(here + 'A');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    for (ll i = 0; i < n; i++){
        char key, lchild, rchild;
        cin >> key >> lchild >> rchild;
        tree[key - 'A'].first = lchild;
        tree[key - 'A'].second = rchild;
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";

    return 0;
}
