#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	void resovle() {
		int n;
		cin >> n;
		vector<string> data(n);
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t >> data[i];
		}
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			int count = 0;
			for (int j = 0; j < data[i].size(); ) {

				if (data[i][j] == '.') {
					j += 3;
					count++;
					/*if (j + 2 < data[i].size()) {
						j += 3;
						count++;
					}
					else if (j + 1 < data[i].size()) {
						j += 2;
						count++;
					}
					else if (j + 2 < data[i].size()) {
						count++;
						res.push_back(count);
						break;
					}*/
				}
				else
					j++;
				if (j >= data[i].size())
				{
					res[i]=(count);
					break;
				}
			}

		}
		for (auto i : res) {
			cout << i << endl;
		}
	}
	Solution();
	~Solution();

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}
int main(void)
{
	Solution s;
	s.resovle();
	system("pause");
}