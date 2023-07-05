
#include <iostream> 

using namespace std;

vector<double> input_vt(int n){
    vector<double> res(n);
    for (int i = 0; i < n; i++){
        cin >> res[i];
    }
    return res;
}

double solve(double x0, int n, vector<double> x, vector<double> y){
    double res = 0, temp = 1;
    for (int i = 0; i < n; i++){
        temp = y[i];
        for (int j = 0; j < n; j++){
            if ( i != j){
                temp *= (x0 - x[j])/(x[i] - x[j]);
            }
        }
        res += temp;
    }
    return res;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("INP.TXT", "r", stdin);
    //freopen("OUT.TXT", "w", stdout);
    #endif

    int n; cin >> n;
    double x0;
    vector<double> x(n), y(n);

    x = input_vt(n);
    y = input_vt(n);

    cin >> x0;

    cout << "Nghiem noi suy cua pt la: " << solve(x0, n, x, y) << endl;

    return 0;
}