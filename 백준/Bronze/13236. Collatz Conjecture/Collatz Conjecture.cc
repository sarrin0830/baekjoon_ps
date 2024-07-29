#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (1) {
		cout << n << ' ';
		if (n == 1) {
			break;
		}
		else if (n % 2 == 0) {
			n /= 2;
		}
		else if (n % 2 != 0) {
			n = n * 3 + 1;
		}
	}



	return 0;
}