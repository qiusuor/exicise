#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char> appear;
		int len = INT_MIN;
		int i = 0;
		int j = 0;
		while (j < s.size()) {
			if (j<s.size()&&!appear.count(s[j])) {
				appear.insert(s[j++]);
			}
			else {
				if (j - i > len)
					len = j - i;
				while (i<j&&s[i] != s[j])
					appear.erase(s[i++]);
				appear.erase(s[i++]);
			}
		}
		return max(appear.size(),len);
	}
	int max(int a, int b) {
		return a > b ? a : b;
	}
};

int main(void) {
	Solution s;
	string a = "aab";
	cout << s.lengthOfLongestSubstring(a);
	system("pause");
}