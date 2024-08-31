#include<iostream>
using namespace std;
int main() {
	int n;
	int sum = 0;
	int mSum = 0;
	int ySum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sum;
		ySum += (sum / 30) * 10;
		ySum += 10;

		mSum += (sum / 60) * 15;
		mSum += 15;
	}
	
	

	if (mSum == ySum) {
		cout << "Y M " << mSum;
	}
	else if (mSum < ySum) {
		cout << "M " << mSum;
	}
	else {
		cout << "Y " << ySum;
	}
	return 0;
} 