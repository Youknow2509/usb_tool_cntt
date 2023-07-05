
#include <iostream>
#include <math.h>

using namespace std;

const double E = 0.1;

double f(double x){
	return pow(x, 3) + 4*pow(x, 2) - 10;
}

bool check(double a, double b, double f){
	if ( abs(a - b)/abs(a) <= E){
		return true;
	}
	if (abs(f) <= E){
		return true;
	}
	return false;
}

double solve (double a, double b, long long n){
	long long count_r = 0;
	double s, e, m;

	s = a; e = b;

	while(count_r < n){
		m = (s + e)/2;
		if (check(s, e, f(m))){
			break;
		}
		if (f(a)*f(m) < 0){
			s = a; e = m;
		}
		else {
			s = m; e = b;
		}
		count_r ++;
	}
	return m;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("INP.TXT", "r", stdin);
	freopen("OUT.TXT", "w", stdout);
	#endif

	double a, b; // nghiệm của pt trong đoạn [a, b]
	long long  n; // số lần chạy tối đa của pt (có thể cho n thật bé để tính nghiệm thứ n)

	n = 1000000000000;

	cin >> a >> b;

	cout << "F(x) = 0 trong [" << a << " , " << b << " ] => x = " << solve(a, b, n) << endl; 

	return 0;
}