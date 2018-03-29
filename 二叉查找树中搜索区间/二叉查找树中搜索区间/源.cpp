#include <iostream>
#include <vector>

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



class Solution {
public:
	/*
	* @param root: param root: The root of the binary search tree
	* @param k1: An integer
	* @param k2: An integer
	* @return: return: Return all keys that k1<=key<=k2 in ascending order
	*/
	void infixOrder(TreeNode * root, int k1, int k2, vector<int> &result) {
		if (root->left)
			infixOrder(root->left, k1, k2, result);
		if (root->val >= k1 && root->val <= k2)
			result.push_back(root->val);
		
		if (root->right)
			infixOrder(root->right, k1, k2, result);
	}
	vector<int> searchRange(TreeNode * root, int k1, int k2) {
		// write your code here
		vector<int> result;
		if (root) {
			infixOrder(root, k1, k2, result);
		}
		finish:
		return result;
	}
};