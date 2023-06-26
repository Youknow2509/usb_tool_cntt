
#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    // Định nghĩa hàm f(x) của phương trình
    return pow(M_E, x) + sin(x) - 5*x - 7;
}

double derivative(double x) {
    // Định nghĩa hàm f'(x) (đạo hàm của f(x))
    return pow(M_E, x) + cos(x) - 5;
}

double newtonMethod(double x0, double epsilon, int maxIterations) {
    double x = x0;
    int iteration = 0;

    while (std::abs(f(x)) >= epsilon && iteration < maxIterations) {
        double delta_x = f(x) / derivative(x);
        x = x - delta_x;
        iteration++;
    }

    std::cout << "Số lần lặp: " << iteration << std::endl;

    return x;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("INP.TXT", "r", stdin);
    freopen("OUT.TXT", "w", stdout);
    #endif

    double x0;       // Điểm ban đầu x0
    double epsilon;  // Sai số epsilon
    int maxIterations; // Số lần lặp tối đa

    cin >> x0 >> epsilon >> maxIterations;

    double root = newtonMethod(x0, epsilon, maxIterations);

    std::cout << "Nghiệm của phương trình: " << root << std::endl;

    return 0;
}
