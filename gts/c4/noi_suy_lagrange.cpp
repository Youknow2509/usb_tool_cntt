
#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x;
    double y;
};

double interpolateLagrange(double x, const std::vector<Point>& points) {
    double result = 0.0;

    for (size_t i = 0; i < points.size(); ++i) {
        double term = points[i].y;

        for (size_t j = 0; j < points.size(); ++j) {
            if (i != j) {
                term *= (x - points[j].x) / (points[i].x - points[j].x);
            }
        }
        result += term;
    }

    return result;
}

int main() {

    int n; // Co n diem

    cin >> n;

    std::vector<Point> points(n);

    for (int i = 0; i < n; i++){
        cin >> points[i].x;
    }
    for (int i = 0; i < n; i++){
        cin >> points[i].y;
    }

    double x; // Giá trị x cần nội suy

    cin >> x;

    double interpolatedValue = interpolateLagrange(x, points);

    std::cout << "Giá trị nội suy tại x = " << x << " là: " << interpolatedValue << std::endl;

    return 0;
}
