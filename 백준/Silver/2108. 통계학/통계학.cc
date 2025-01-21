#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <map>
using namespace std;

#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Info {
	int clas;
	string name;
};

int RR(double n, int size) {
	int k=
	n /= size;
	n = round(n);
	return (int)n;
}

int main() {
	fastIo;
	int n;
	cin >> n;
	int input;
	double sum = 0;
	int minI = 5000001, maxI = -5000001;
	vector<int>v;
	vector<int>bin;
	map<int, int>m;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v.push_back(input);
		sum += input;
		if (input < minI)
			minI = input;
		if (input > maxI)
			maxI = input;
		if (m.count(input) == 0) {
			bin.push_back(input);
			m.insert({ input, 1 });
		}
		else
			m[input]++;
	}
	
	bool check = false;
	sort(v.begin(), v.end());
	sort(bin.begin(), bin.end());
	int binMax = bin[0];
	for (int i = 1; i < bin.size(); i++)
	{
		if (m[binMax] == m[bin[i]]&&!check) {
			check = true;
			binMax = bin[i];
		}
		if (m[binMax] < m[bin[i]]){
			check = false;
			binMax = bin[i];
		}
	}


	cout << RR(sum, n) << "\n";
	cout << v[n / 2] << "\n";
	cout << binMax << "\n";
	cout << maxI - minI << "\n";

}

