
#include <iostream>	

using namespace std;

const double h = 0.000000001;

double f(double x){
	return x*x - 2*x + 1;
}

double f_ (double x){
	return (f(x + h) - f(x))/h;
}

int main(){

	double x; cin >> x;

	cout << "F'(" << x << ") = " << f_(x) << endl;

	return 0;	
}