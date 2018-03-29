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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *r;
		int t = l1->val + l2->val;
		bool c;
		if (t > 9) {
			c = true;
		}
		else
			c = false;
		r = new ListNode(t%10);
		ListNode *cur = r;
		l1 = l1->next;
		l2 = l2->next;

		while (l1 || l2) {
			if (l1 && l2) {
				t = l1->val + l2->val+c;
				cur->next = new ListNode(t % 10 );
				if (t > 9) {
					c = true;
				}
				else
					c = false;
				cur = cur->next;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1) {
				t = l1->val  + c;
				cur->next = new ListNode(t % 10);
				if (t > 9) {
					c = true;
				}
				else
					c = false;
				cur = cur->next;
				l1 = l1->next;
			}
			else {
				t =  l2->val + c;
				cur->next = new ListNode(t % 10);
				if (t > 9) {
					c = true;
				}
				else
					c = false;
				cur = cur->next;
				l2 = l2->next;
			}
		}
		if (c) {
			cur->next = new ListNode(1);
			cur = cur->next;
		}
		return  r;
	}
};
int main(void) {
	ListNode *l1 = new ListNode(9);
	

	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(9);
	l2->next->next->next = new ListNode(9);
	l2->next->next->next->next = new ListNode(9);
	l2->next->next->next->next->next = new ListNode(9);
	l2->next->next->next->next->next->next = new ListNode(9);
	l2->next->next->next->next->next ->next->next= new ListNode(9);
	l2->next->next->next->next->next->next->next->next = new ListNode(9);
	l2->next->next->next->next->next->next->next->next->next = new ListNode(9);

	Solution s;
	ListNode* l=s.addTwoNumbers(l1, l2);
	cout << l->val;
	system("pause");
}