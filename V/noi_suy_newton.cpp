
#include <iostream> 
#include <vector>

using namespace std;

vector<vector<double> > tao_he_so(int n, vector<double> x, vector<double> y){
    vector<vector<double> > res(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++){
        res[i][0] = y[i];
    }
    for (int j = 1; j < n; j++){
        for (int i = 0; i < n - j; i++){
            res[i][j] = (res[i + 1][j - 1] - res[i][j - 1])/(x[i + j] - x[i]);
        }
    }
    return res;
}

double solve(double x0, int n, vector<double> x, vector<double> y){
    vector<vector<double > > btsp = tao_he_so(n, x, y);
    double res = y[0], temp = 1;
    for (int i = 1; i < n; i++){
        temp *= x0 - x[i];
        res += temp*btsp[0][i];
    }
    return res;
}

vector<double> nhap(int n){
    vector<double> x(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    return x;
}

int main(){

    /* #ifndef ONLINE_JUDGE
    freopen("INP.TXT", "r", stdin);
    freopen("OUT.TXT", "w", stdout);
    #endif */

    int n;  cin >> n;
    vector<double> x(n), y(n);
    double x0;

    x = nhap(n);
    y = nhap(n);


    cin >> x0;

    cout << "Noi suy gia tri tai x0 la: " << solve(x0, n, x, y) << endl;

    return 0;
}
