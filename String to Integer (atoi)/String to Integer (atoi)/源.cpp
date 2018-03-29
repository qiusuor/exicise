#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string.h>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int ans = 0;
		int i = 0;
		int t = 0;
		bool f = true;
		bool sign = true;
		bool sf = true;
		while (i < str.size())
		{
			if (isspace(str[i])&&f) {
				i++;
				continue;
			}
			f = false;
			if (str[i] >= '0' && str[i] <= '9') {
				if ((ans * 10 + str[i] - 48) / 10 != t)
					return sign ? INT_MAX : INT_MIN;
				ans = ans * 10 + str[i] - 48;
				t = ans;
			}
			else if (str[i] == '-' &&sf) {
				sf = false;
				sign = false;
			}
			else if (str[i] == '+' &&sf)
				sf = false;
			else if(!f)
				break;
			i++;
		}

		return sign?ans:-ans;
	}
};

int main(void) {
	Solution s;
	string a = "aab";
	cout << s.myAtoi("2147483648");
	//cout << s.lengthOfLongestSubstring(a)
	system("pause");
}