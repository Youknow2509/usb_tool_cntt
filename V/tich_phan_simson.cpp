
#include <iostream>

using namespace std;

const int d = 10000; // d phải là số chẵn

double f (double x){
	return x*x - 2*x + 1;
}

double tich_phan_f (double a, double b){
	double res = f(a) + f(b),
		h = (b - a)/d;
	for (int i = 1; i < d; i++){
		if (i % 2 == 0){
			res += f(a + i*h)*2;
		}
		else {
			res += f(a + i*h)*4;
		}
	}
	return res*h/3;
}

int main(){

	double a, b; cin >> a >> b;

	cout << "Tich phan tu " << a << " den " << b << " cua ham so F(x) theo cong thuc simson la: " << tich_phan_f(a, b) << endl;

	return 0;
}