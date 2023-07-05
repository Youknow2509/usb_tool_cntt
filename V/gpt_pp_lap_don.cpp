
#include <iostream>
#include <math.h>

using namespace std;

const E = 0.000001;
const double INF = 1000000000000; 

double f (double x){
	return pow(x, 3) + 4*pow(x, 3) - 10;
}
// => Ta cần tìm x(n) = g(x(n-1)) 
double g (double x){
	return 0; // Để tạm hàm g(x) cần sửa lại hàm g(x) để đoạn mã chạy
}
double solve(double X, int Run){
	double next_X = INF;
	int counst_run = 0;
	while (counst_run < Run){
		if (abs(next_X - X) < E){
			break;
		}
		next_X = g(X);
		X = next_X;
		counst_run++:
	}
	return X;
}

int main(){

	double x0; 
	int N;
	cout << "Nhap nghiem xuat phat: " << endl; cin << x0;
	cout << "Nhap so lan chay toi da: " << N << endl; cin << N;
	cout << "Nghiem cua phuong trinh la: " << solve(x0, N) << endl;
	
	return 0;
}