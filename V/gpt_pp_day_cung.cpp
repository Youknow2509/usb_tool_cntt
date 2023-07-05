
#include <iostream>
#include <math.h>

using namespace std;

const double E = 0.00000001;

double f (double x){
	return x*x*x +4*x*x - 10;
}

bool check(double s, double e, double f){
	if (abs(e - s) < E){
		return true;
	}
	if ( abs(f) < E){
		return true;
	}
	return false;
}

double solve(double a, double b, int N){
	int c = 0;
	double s = a, e = b, m, temp;
	while (c < N){
		m = s - f(s)*(s - e)/(f(s) - f(e));
		temp = f(m);
		if (check(s, e, temp)){
			break;
		}
		if (f(s)*temp < 0){
			s = a; e = m;
		}
		else {
			s = m; e = b;
		}
		c++;
	}
	return m;
}

int main(){

	/* #ifndef ONLINE_JUDGE
	freopen("INP.TXT", "r", stdin);
	freopen("OUT.TXT", "w", stdout);
	#endif */

	int n;
	double a, b;
	cout << "Nhap khoang nghiem: " << endl; cin >> a >> b;
	cout << "Nhap so lan chuong trinh chay toi da: " << endl; cin >> n;
	cout << "Nghiem cua phuong trinh la: " << solve(a, b, n) << endl;

	return 0;
}