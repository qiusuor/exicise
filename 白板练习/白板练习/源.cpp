#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <bitset>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

#define SWAP_INT(a,b) {a=a^b;b=a^b;a=a^b;}

//#ifndef INT_MIN
//#define INT_MIN 1<<32
//#endif

class Solution {
public:

	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() <= 0) return true;
		vector<int> posSmallerEquel(sequence.size());
		vector<int> biggest(sequence.size());
		biggest[0] = sequence[0];
		//int tmp = biggest[0];
		for (int i = 1; i < biggest.size(); i++) {
			if (sequence[i] > biggest[i - 1])
				biggest[i] = sequence[i];
			else
				biggest[i] = biggest[i - 1];
		}
		posSmallerEquel[0] = -1;
		for (int j = 1; j < sequence.size(); j++)
		{
			if (sequence[j] > sequence[j - 1])
				posSmallerEquel[j] = j - 1;
			else {
				int t = posSmallerEquel[j - 1];
				while (sequence[j] < sequence[t] && t>=0) {
					t = posSmallerEquel[t];
				}
				posSmallerEquel[j] = t;
			}
		}
		for (int i = sequence.size()-1; i>=0; i--)
			if (sequence[posSmallerEquel[i]]<biggest[posSmallerEquel[i]])
				return false;

		return true;
	}
};
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	long long n, k;
	cin >> n >> k;
	long long sum = 0;
	if (k == 0) {
		unsigned long long t = n*n;
		cout << t;
		return 0;
	}
	for (int y = k + 1; y <= n; y++) {

		int p = (n + 1) / y - 1;
		if (p >= 0)
			sum += (p + 1)*(y - k);
		if ((p + 1)*y + k <= n)
			sum += n - ((p + 1)*y + k) + 1;
	}
	cout << sum;
	system("pause");

}