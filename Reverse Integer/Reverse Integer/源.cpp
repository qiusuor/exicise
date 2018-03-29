#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int ans = 0;
		int tmp = 0;
		while (x) {
			if ((ans * 10 + x % 10) / 10 != tmp)
				return 0;
			ans = ans*10+x % 10;
			tmp = ans;
			x /= 10;
		}
		return ans;
	}
};

int main(void) {
	Solution s;
	string a = "aab";
	
	//cout << s.lengthOfLongestSubstring(a);
	cout << s.reverse(123);
	system("pause");
}