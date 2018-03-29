#include <iostream>
#include <vector>
#include <string>

using namespace std;


class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};



class MinStack {
public:
	MinStack() {
		// do intialization if necessary
	}

	/*
	* @param number: An integer
	* @return: nothing
	*/
	void push(int value) {

		if (stk.size() == 0) {

			stk.push_back(value);

			min_pos.push_back(0);

			mini = value;

		}

		else {

			stk.push_back(value);

			if (mini >= value) {

				min_pos.push_back(stk.size() - 1);

				mini = value;

			}

		}

	}

	int pop() {
		int ans = top();
		if (stk[stk.size() - 1] == mini) {

			min_pos.pop_back();
			mini = stk[min_pos[min_pos.size() - 1]];
		}

		stk.pop_back();
		return ans;
	}

	int top() {

		return stk[stk.size() - 1];

	}

	int min() {

		return stk[min_pos[min_pos.size() - 1]];

	}

	vector<int> stk;

	vector<int> min_pos;

	int mini;

};