
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

vector<double> solve(int n, vector<vector<double> > A, vector<double> B){
    vector<double> res(n);
    
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
