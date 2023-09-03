#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

long long int mod(long long int, long long int, long long int, long long int);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int ans = mod(b, a, b, c);

    cout << ans << "\n";

    return 0;
}

long long int mod(long long int n, long long int a, long long int b, long long int c){
    long long int ans = a % c;
    if (n == 1){
        //cout << ans << "\n";
        return ans;
    }
    long long int mul = n / 2;
    long long int p = mod(mul, a, b, c);

    if (!(n % 2)){ 
        //cout << ((p % c) * (p % c)) % c << "\n";
        return (p * p) % c;
    }
    else {
        //cout << ((p % c) * (p % c) * ans) % c << "\n";
        return (((p * p) % c) * a) % c;
    }
}
