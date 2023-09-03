#include <iostream>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int i, j, mul = 1, div_1 = 1, div_2 = 1;
    for (i = 0; i < n; i++) mul *= (i + 1);
    for (i = 0; i < k; i++) div_1 *= (i + 1);
    for (i = 0; i < n - k; i++) div_2 *= (i + 1);
    int ans = mul / (div_1 * div_2);
    cout << ans << "\n";
    
    return 0;
}
