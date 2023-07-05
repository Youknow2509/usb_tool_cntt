
#include <iostream>

using namespace std;
	
const int d = 100000;

double f (double x){
	return x*x - 2*x + 1;		
}

double tich_phan_f (double a, double b){
	double res = f(a) + f(b),
		h = (b - a)/d;
	for (double i = a + h; i < b; i += h ){
		res += 2*f(i);	
	}
	return res*h/2;
}

int main(){

	double a, b; cin >> a >> b;

	cout << "Tich phan tu " << a << " den " << b << " cua ham so F(x) theo cong thuc hinh thang la: " << tich_phan_f(a, b) << endl;

	return 0;
}