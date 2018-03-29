#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> &nums, int target, int i, int j) {
	int p1 = -1;
	int p2 = -1;
	int ii = i;
	int jj = j;
	int mid = (ii + jj) / 2;
	int jjj = j;
	while (ii <= jj) {
		if (nums[mid] > target) {
			jj = mid - 1;
		}
		else if (nums[mid] <= target) {
			ii = mid + 1;
		}
		mid = (ii + jj) / 2;
	}
	if (jj >= 0 && nums[jj] == target)
		p1= jj;

	mid = (i + j) / 2;
	while (i <= j) {
		if (nums[mid] >= target) {
			j = mid - 1;
		}
		else if (nums[mid] < target) {
			i = mid + 1;
		}
		mid = (i + j) / 2;
	}
	if (i<=jjj && nums[i] == target)
		p2=i;
	if (p2 == -1) return 0;
	return p1 - p2+1;
}
int main(void) {
	int n;
	cin >> n;
	cin.get();
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		nums[i] = tmp;
	}

	
	if (n <= 1) cout << "0 0";
	sort(nums.begin(), nums.end());

	int minDis = 0;
	int maxDis = 0;

	minDis = nums[nums.size() - 1] - nums[nums.size() - 2];
	maxDis = nums[nums.size() - 1] - nums[0];

	int minPairs = 0;
	int maxPairs = 0;

	

	for (int i = 0; i < nums.size(); i++) {
		minPairs += binarySearch(nums, nums[nums.size() - 1 - i] - minDis, 0, nums.size() - 2 - i);
		//cout << binarySearch(nums, nums[nums.size() - 1 - i] - minDis, 0, nums.size() - 2 - i)<<endl;
		
		maxPairs += binarySearch(nums, nums[nums.size() - 1 - i] - maxDis, 0, nums.size() - 2 - i);
	}
	cout << minPairs << " " << maxPairs;
	//system("pause");
}
