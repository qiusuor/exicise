#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <fstream>
#include <set>
#include <string>

/*
O(n)
*/
#ifndef INT_MIN
#define INT_MIN 1<<32
#endif // !INT_MIN

using namespace std;

class Solutin {
public:
	int binarySearch(vector<pair<int, int>>&work, int target) {
		int l = 0;
		int r = work.size() - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (work[mid].first > target)
				r = mid - 1;
			else
				l = mid + 1;

		}
		return work[r].second;
	}
	bool cmp(const pair<int, int>a, const pair<int, int>b) {
		return a.first < b.first;
	}
	void resolve() {
		int n, m;
		cin >> n >> m;
		unsigned long long sum = 0;
		unsigned long long cur = 0;
		for (int i = 1; i <= m; i++) {
			cur += i;
			if (cur % 3 == 0 && n <= i &&i <= m)
				sum++;
		}
		cout << sum;
		/*vector<pair<int, int>> work(n);
		vector<int> person(m);
		for (int i = 0; i < n; i++) {
			cin >> work[i].first >> work[i].second;
		}


		for (int i = 0; i < m; i++)
			cin >> person[i];
		sort(work.begin(), work.end());
		int max_salary = INT_MIN;
		for (int i = 0; i < work.size(); i++) {
			if (work[i].second < max_salary) {
				work[i].second = max_salary;
			}
			else
				max_salary = work[i].second;
		}

		for (int i = 0; i < m; i++) {
			cout << binarySearch(work, person[i]) << endl;
		}*/
	}
};


int main(void) {
	Solutin s;
	s.resolve();
	system("pause");
}