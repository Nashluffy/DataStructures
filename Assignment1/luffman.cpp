#include <iostream>
#include <math.h>
using namespace std;
int karatsuba(int lhs, int rhs){
	int finalProduct, eMultiplication , lhsLow, lhsHigh, rhsLow, rhsHigh, a, e, n, d, m;
	if (to_string(rhs).length() && to_string(lhs).length()){ //base case, when it is a single digit number
		return lhs * rhs;	
	}
	else{
		n = max(to_string(rhs).length(),to_string(lhs).length());
		m = ceil((double(n)/2)); //It's important for this to be rounded up in odd-numbered n cases
		lhsLow = lhs%int((pow(double(10),m)));
		rhsLow = rhs%int((pow(double(10),m)));
		lhsHigh = lhs/int((pow(double(10),m)));
		rhsHigh = rhs/int((pow(double(10),m)));
		a = karatsuba(lhsHigh,rhsHigh);
		d = karatsuba(lhsLow, rhsLow);
		e = karatsuba((lhsHigh+lhsLow),(rhsHigh+rhsLow)) - a - d;
		//The reason the finalProduct is a*10^(2*m) is to handle odd-numbered n cases where m has been rounded up
		finalProduct = a*int(pow(double(10),karatsuba(2,m))) + e*int(pow(double(10),m)) + d; 
	}
	return finalProduct;
};
int main() {
	cout << "7*6 = " << karatsuba(7,6) << endl; //42
	cout << "15*15 = " << karatsuba(15,15) << endl; //225
	cout << "6*13 = " << karatsuba(6,13) << endl; //78
	cout << "51*49 = " << karatsuba(51,49) << endl; //2499
	cout << "234*567 = " << karatsuba(111,111) << endl; //12321
	cout << "5678*1234 = " << karatsuba(5678,1234) << endl; //7006652	
	cout << "12345678*1 = " << karatsuba(12345678,1) << endl; //12345678
	cout << "12345678*0 = " << karatsuba(12345678,0) << endl; //0
	return 0;	
}
