#include <iostream>
#include <string>


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    double a;
    std::cin >> a;
    double* p = new double[int(a)];
    int t1;
    for (t1 = 0; t1 < a; t1++)
        std::cin >> p[t1];
    double max = 0;
    for (t1 = 0; t1 < a; t1++) {
        if (p[t1] > max) max = p[t1];
    }
    for (t1 = 0; t1 < a; t1++)
        p[t1] = (p[t1] / max) * 100;
    double sum = 0;
    for (t1 = 0; t1 < a; t1++)
        sum += p[t1];
    double avr = sum / a;
    std::cout.precision(8);
    std::cout << avr;
    delete[] p;
    return 0;
}
