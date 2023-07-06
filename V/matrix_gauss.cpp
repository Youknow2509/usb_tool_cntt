
#include <iostream>
#include <vector>

using namespace std;

vector<vector<double> > input_vt_A(int n){
    vector<vector<double> > A(n, vector<double>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    return A;
}

vector<double> input_vt_B(int n){
    vector<double> B(n);
    for (int i = 0; i < n; i++){
        cin >> B[i];
    }
    return B;
}

vector<vector<double> > tao_ma_tran_mo_rong_bac_thang(int n, vector<vector<double> > A, vector<double> B){
    vector<vector<double> > res(n, vector<double>(n + 1));
    double he_so = 0;
    // Tao ma tran mo rong
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n + 1; j++){
            if (j < n){
                res[i][j] = A[i][j];
            }
            else{
                res[i][j] = B[i];
            }
        }
    }
    // Khu gauss
    for (int k = 0; k < n - 1; k++){
        for (int i = k + 1; i < n; i++){
            he_so = res[i][k]/res[k][k];
            for (int j = 0; j < n + 1; j++){
                res[i][j] -= he_so*res[k][j];
            }
        }
    }
    return res;
}

vector<double> solve(int n, vector<vector<double> > A, vector<double> B){
    vector<vector<double> > matrix = tao_ma_tran_mo_rong_bac_thang(n, A, B);
    vector<double> res(n);
    double temp, x;
    for (int i = n - 1; i >= 0; i--){
        temp = 0;
        for (int j = i + 1; j < n; j++){
            temp += res[j]*matrix[i][j];
        }
        res[i] = (matrix[i][n] - temp)/matrix[i][i];
    }
    return res;
}

void in_vt(int n, vector<double> res){
    for (int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("INP.TXT", "r", stdin);
    #endif

    int n; cin >> n;
    vector<vector<double> > A(n, vector<double>(n));
    vector<double> B(n);

    A = input_vt_A(n);
    B = input_vt_B(n);

    cout << "Matrix nghiem la: " << endl;

    in_vt(n, solve(n, A, B));

    return 0;
}
