#include <iostream>
#include <cmath>

using namespace std;

double equation(double x) {
    // Hàm này đại diện cho phương trình cần giải
    // Thay đổi phương trình theo yêu cầu của bạn
    return x * x - 4;
}

double fixedPointIteration(double initialGuess, double epsilon, int maxIterations) {
    double currentX = initialGuess;
    double nextX;
    int iterations = 0;
    
    while (iterations < maxIterations) {
        nextX = equation(currentX); // Áp dụng công thức lặp
        if (abs(nextX - currentX) < epsilon) {
            return nextX; // Kết quả gần đúng
        }
        currentX = nextX;
        iterations++;
    }
    
    return nextX; // Kết quả gần đúng sau số lần lặp tối đa
}

int main() {
    double initialGuess, epsilon;
    int maxIterations;
    
    cout << "Nhập giá trị ban đầu: ";
    cin >> initialGuess;
    
    cout << "Nhập độ chính xác epsilon: ";
    cin >> epsilon;
    
    cout << "Nhập số lần lặp tối đa: ";
    cin >> maxIterations;
    
    double result = fixedPointIteration(initialGuess, epsilon, maxIterations);
    
    cout << "Nghiệm gần đúng của phương trình là: " << result << endl;
    
    return 0;
}
