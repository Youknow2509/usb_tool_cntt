
#include <iostream>
#include <math.h>

using namespace std;

const double E = 0.0000001;

double f(double x){
	return x*x*x + 4*x*x - 10;
}

double f_(double x){
	return (f(x + E) - f(x))/E;
}

bool check(double x1, double x2, double f){
	if (abs(x2 - x1) < E){
		return true;
	}
	if (abs(f) < E){
		return true;
	}
	return false;
}

double solve(double x, int N){
	double next_X = x;
	int c = 0;
	while (c < N){
		next_X = x - f(x)/f_(x);
		if (check(x, next_X, f(next_X))){
			break;
		}
		x = next_X;
		c++;
	}
	return next_X;
}

int main(){

	double x; cout << "Nhap diem xuat phat: " << endl; cin >> x;
	int N; cout << "Nhap so la chay: " << endl; cin >> N;
	cout << "Nghiem cua phuong trinh la: " << solve(x, N) << endl;

	return 0;
}