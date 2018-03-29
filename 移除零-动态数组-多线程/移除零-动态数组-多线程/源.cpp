#include <vector>
#include <iostream>
#include <ctime>
#include <mutex>
#include <thread>
#include <algorithm>


#define SCALE 100000000

using namespace std;

class Solution {
public:
	/**
	* @param nums an integer array
	* @return nothing, do this in-place
	*/
	int th(int *nums, int start, int end) {
		vector<int> zero_pos;
		//mutex m;
		for (int i = start; i < end; i++)
		{
			if (nums[i] == 0)
			{
				zero_pos.push_back(i);
			}
		}
		if (zero_pos.size() && zero_pos[0] < end - 1) {
			int sum = 1;
			for (size_t i = zero_pos[0] + 1; i < end; i++)
			{
				if (sum < zero_pos.size() && i == zero_pos[sum]) sum++;
				else nums[i - sum] = nums[i];
			}
			for (size_t i = 0; i < zero_pos.size(); i++)
			{
				nums[end - zero_pos.size() + i] = 0;
			}
		}
		return zero_pos.size();
	}
	void moveZeroes(int* nums) {
		// Write your code here
		//mutex m;

		//th(nums, 0, SCALE);
		
	}
};






int main(void) {
	clock_t start = clock();
	int *aa = NULL;
	int *nums = new int[SCALE];
	clock_t end = clock();
	cout << "申请动态内存: " << end - start << endl;
	start = clock();
	for (int i = 0; i<100000000; i++)
	{
		nums[i] = rand();
	}
	end = clock();
	cout << "产生随机数组: " << end - start << endl;
	int *nums_cp = new int[SCALE];
	start = clock();
	memcpy(nums_cp, nums, SCALE * sizeof(int));

	end = clock();
	cout << "内存拷贝: " << end - start << endl;

	Solution s;
	start = clock();
	s.moveZeroes(nums);
	end = clock();
	cout << "移除非法元素到末尾: " << end - start << endl;

	for (int i = 99997010; i<SCALE; i++)
	{
		/*if (nums[i] == 0) {
		cout << i;
		break;
		}*/
		if (nums[i] != 0) cout << "err";
	}

	system("pause");
}