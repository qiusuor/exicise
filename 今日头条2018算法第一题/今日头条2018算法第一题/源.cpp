#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

#ifndef INT_MIN
#define INT_MIN 1<<32
#endif // !INT_MIN


bool cmp(const pair<int, int>a, const pair<int, int>b) {
	return a.first < b.first;
}
int max(int a, int b) { return a < b ? b : a; }
int main(void) {
	int n;
	cin >> n;
	vector<pair<int, int>> data(n);
	
	for (int i = 0; i < n; i++) {
		cin >> data[i].first;
		cin >> data[i].second;
	}
	sort(data.begin(), data.end(), cmp);

	int maxY = INT_MIN;
	vector<pair<int, int>> result;
	for (int i = n - 1; i >= 0; i--) {
		if (data[i].second > maxY) {
			result.push_back(data[i]);
			maxY = data[i].second;
		}
	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i].first << " " << result[i].second << endl;
	}

	system("pause");

}