
#include <iostream>
#include <vector>

using namespace std;

// Tính bảng tỉ sai phân
std::vector<std::vector<double> > calculateForwardDifferences(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    std::vector<std::vector<double> > forwardDifferences(n, std::vector<double>(n)); // Tạo ma trận vuông kích thước n*n
    
    // Sao chép giá trị y vào cột đầu tiên của bảng tỉ sai phân
    for (int i = 0; i < n; i++) {
        forwardDifferences[i][0] = y[i];
    }
    
    // Tính các tỉ sai phân
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            forwardDifferences[i][j] = (forwardDifferences[i + 1][j - 1] - forwardDifferences[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    return forwardDifferences;
}

int main() {
    std::vector<double> x; // {0, 1, 2, 3}; // Các giá trị x
    std::vector<double> y;// {1, 4, 9, 16}; // Các giá trị y
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++){
        double temp;
        cin >> temp;
        x.push_back(temp);
    }
    for (int i = 0; i < n; i++){
        double temp;
        cin >> temp;
        y.push_back(temp);
    }
    std::vector<std::vector<double> > forwardDifferences = calculateForwardDifferences(x, y);

    // In ra bảng tỉ sai phân
    std::cout << "Bảng tỉ sai phân:\n";
    for (int i = 0; i < forwardDifferences.size(); i++) {
        std::cout << "D" << i << "y: ";
        for (int j = 0; j < forwardDifferences[i].size(); j++) {
            std::cout << forwardDifferences[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
