#include<iostream>
#define ll long long int
#define div 1000000007
using namespace std;
ll n;
struct Matrix
{
	ll Ma[2][2];

	Matrix() {
		Ma[0][0] = 1;
		Ma[1][0] = 1;
		Ma[0][1] = 1;
		Ma[1][1] = 0;
	}
};

Matrix mul(Matrix a, Matrix b) {
	Matrix newMatrix;
	newMatrix.Ma[0][0] = ((a.Ma[0][0] * b.Ma[0][0]) % div + (a.Ma[0][1] * b.Ma[1][0]) % div) % div;
	newMatrix.Ma[0][1] = ((a.Ma[0][0] * b.Ma[0][1]) % div + (a.Ma[0][1] * b.Ma[1][1]) % div) % div;
	newMatrix.Ma[1][0] = ((a.Ma[1][0] * b.Ma[0][0]) % div + (a.Ma[1][1] * b.Ma[1][0]) % div) % div;
	newMatrix.Ma[1][1] = ((a.Ma[1][0] * b.Ma[0][1]) % div + (a.Ma[1][1] * b.Ma[1][1]) % div) % div;
	return newMatrix;
}
Matrix cal(Matrix a, ll k) {
	if (k > 1) {
		a = cal(a, k / 2);
		a = mul(a, a);
		if (k % 2 == 1) {
			Matrix curMat;
			a = mul(a, curMat);
		}
	}
	return a;
}

ll fibo(ll k) {
	if (k == 0) {
		return 0;
	}
	else if (k <= 2) {
		return 1;
	}
	else {
		Matrix curMat;
		return (cal(curMat, k)).Ma[0][1] % div;
	}
}




int main() {
	ios::sync_with_stdio();
	cin.tie();
	cin >> n;
	cout << fibo(n) % div;
	return 0;
}