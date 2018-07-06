#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;




bool cmp(const pair<int, int> a, const pair<int, int> b) {
	return a.first * 60 + a.second < b.first * 60 + b.second;
}


int main(void) {
	int n;
	cin >> n;
	vector<pair<int, int>> clock(n);
	for (int i = 0; i < n; i++)
	{
		cin >> clock[i].first >> clock[i].second;
	}
	int timeNeed;
	cin >> timeNeed;
	pair<int, int> toArrive;
	cin >> toArrive.first >> toArrive.second;
	
	//sort(clock.begin(), clock.end(), cmp);
	int index = -1;
	int minRes = 1<<30;
	int latest = toArrive.first * 60 + toArrive.second - timeNeed;
	for(int i=0;i<n;i++)
		if (minRes > latest - clock[i].first * 60 - clock[i].second && latest - clock[i].first * 60 - clock[i].second >= 0)
		{
			index = i;
			minRes = latest - clock[i].first * 60 - clock[i].second;
		}
	cout << clock[index].first << " " << clock[index].second;
	system("pause");
}