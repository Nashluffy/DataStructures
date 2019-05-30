#include <iostream>
#include <math.h>
using namespace std;

int numLength(int num){
	int numLength;
	numLength = to_string(num).length();
	return numLength;

}


int karatsuba(int lhs, int rhs){
	int finalProduct, eMultiplication , lhsLow, lhsHigh, rhsLow, rhsHigh;
	int a, b, e, n, d, m;
	if (lhs < 10 && rhs < 10){ //base case
		return lhs * rhs;	
	
	}
	else{
		n = max(numLength(rhs),numLength(lhs));
		m = ceil((double(n)/2));	
		lhsLow = lhs%int((pow(double(10),m)));
		rhsLow = rhs%int((pow(double(10),m)));
		lhsHigh = lhs/int((pow(double(10),m)));
		rhsHigh = rhs/int((pow(double(10),m)));
		a = karatsuba(lhsHigh,rhsHigh);
		d = karatsuba(lhsLow, rhsLow);
		eMultiplication = karatsuba((lhsHigh + lhsLow),(rhsHigh + rhsLow));
		e = eMultiplication - a - d;
		
		finalProduct = a*int(pow(double(10),double(n))) + e*int(pow(double(10),m)) + d; 

	}
	return finalProduct;
};

//111*111
//N=3 M=2 XL=11 XH=1 YL=11 YH=1
//a=XH*YH = 1 *1 = 1
//d=XL*YL = 11 * 11 = 121
//e=(XH+XL)*(YH+YL) - a -d = 12 * 12 - 1 - 121 = 22
//X*Y=a*10^N + e*10^(N/2) + d = 1000 + 100 * 22 + 121 = 3321 




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

