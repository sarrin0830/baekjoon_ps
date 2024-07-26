#include<iostream>
#include<cmath>
using namespace std;

int func(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (a > b) {
        return func(b, a);
    }
    return func(b % a, a);
}

int main() {
    int num[5];
    int mim = 1000001;
    for (int i = 0; i < 5; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                int sum = num[j] * num[k];
                int div1 = func(num[j], num[k]);
                sum /= div1;
                int div2 = func(num[i],sum);
                sum =sum/ div2 * num[i];
                if (sum < mim) {
                    mim = sum;
                }
            }
        }
    }

    cout << mim;
    return 0;
}