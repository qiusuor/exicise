#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;


int resolve(int i, int j,vector<int> &v, map<pair<int, int>, int> &dp) {
	if (i<0||v[i]>j  )
		return 1;
	int re;
	if (dp.count(pair<int, int>{i - 1, j}))
		re = dp[pair<int, int>{i - 1, j}];
	else
		re = resolve(i - 1, j, v,dp);
	if (j - v[i] >= 0)
		if (dp.count(pair<int, int>{i - 1, j - v[i]}))
		{
			re+= dp[pair<int, int>{i - 1, j - v[i]}];
		}
		else

			re += resolve(i - 1, j - v[i], v,dp);
	dp[pair<int, int>{i,j}] = re;
	return re;
}
int main(void) {
	int n, w;
	cin >> n >> w;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++)
		cin >> v[i];
	map<pair<int, int>,int> dp;
	sort(v.begin(), v.end(),greater<int>());
	cout << resolve(n-1, w, v,dp);
	system("pause");
}