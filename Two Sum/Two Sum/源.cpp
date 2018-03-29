#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*
O(n)
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> pos;
	
		for (int i = 0; i < nums.size(); i++) {
			if (pos.count(target - nums[i]))
				return { pos[target - nums[i]],i };
			pos[nums[i]] = i;
		}
	}
};

int main(void) {
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(75);
	nums.push_back(25);

	Solution s;


	for (auto i : s.twoSum(nums, 100))
	{
		cout << i << endl;
	}

	system("pause");
}