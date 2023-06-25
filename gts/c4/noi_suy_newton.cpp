
#include <iostream> 
#include <vector>

using namespace std;

double solve(double x0, vector<double> X, vector<double> Y){
    int n = X.size();
    vector<vector<double> > bang_ti_sai_phan(n, vector<double>(n, 0));
    // Tạo bảng tỉ sai phân
        // Lấy các giá trị khởi tạo
    for (int i = 0; i < n; i++){
        bang_ti_sai_phan[i][0] = Y[i];
    }
        // Điền các giá trị vào bảng tỉ sai phân
    for (int j = 1; j < n; j++){
        for (int i = 0; i < n - j; j++){
            bang_ti_sai_phan[i][j] = (bang_ti_sai_phan[i + 1][j - 1] - bang_ti_sai_phan[i][j - 1])/(X[i + j] - X[i]);
        }
    }
    // Tính toán giá trị nội suy tại điểm x0.
    double res = Y[0], temp = 1;
    for (int i = 1; i < n; i++){
        temp *= (x0 - X[i]);
        res += temp*bang_ti_sai_phan[0][i];
    }
    return res;
}

int main(){

    int size_table, temp; cin >> size_table;
    vector<double> X(size_table), Y(size_table);
    double x0;
    // Nhập giá trị của x và f(x).
    for (int i = 0; i < size_table; i++){
        cin >> X[i];
    }
    for (int i = 0; i < size_table; i++){
        cin >> Y[i];
    }
    cin >> x0; // Nhập giá trị cần nội suy tính.
    cout << "F(" << x0 << ")" << " = " << solve(x0, X, Y) << endl;

    return 0;
}