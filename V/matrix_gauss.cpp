
#include <iostream>
#include <vector>

using namespace std;

void nhap_du_lieu(vector<vector<double> >&A, vector<double> &B, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        cin >> B[i];
    }
}

vector<double> solve_gauss (vector<vector<double> > A, vector<double> B, int n){
    vector<vector<double> > C(n, vector<double>(n + 1, 0));
    vector<double> res(n, 0);
    double he_so = 0, s = 0;
    // Tạo ma trận mở rộng C.
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n + 1; j++){
            if (j == n){
                C[i][j] = B[i];
            }
            else{
                C[i][j] = A[i][j];
            }
        }
    }
    // Biến đổi ma trận C thành ma trận hình thang
    for (int k = 0; k < n - 1; k++){
        for (int i = k + 1; i < n; i++){
            he_so = C[i][k]/C[k][k];
            for (int j = 0; j < n + 1; j++){
                C[i][j] -= he_so*C[k][j];
            }
        }
    }
    // Tìm nghiệm 
    for (int i = n - 1; i >= 0; i--){
        s = 0;
        for (int j = i + 1; j < n; j++){
            s += res[j]*C[i][j];
        }
        res[i] = (C[i][n] - s)/C[i][i];
    }
    return res;
}

void in_nghiem (vector<double>X, int n){
    for (int i = 0; i < n; i++){
        cout << X[i] << " ";
    }
    cout << endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("INP.TXT", "r",stdin);
    freopen("OUT.TXT", "w", stdout);
    #endif

    int size_matrix; cin >> size_matrix;
    vector<vector<double> > A(size_matrix, vector<double> (size_matrix));
    vector<double> B(size_matrix), x(size_matrix);
    
    nhap_du_lieu(A, B, size_matrix);

    x = solve_gauss(A, B, size_matrix);

    cout << "Nghiem cua pt: Ax = B la: ";

    in_nghiem(x, size_matrix);

    return 0;
}