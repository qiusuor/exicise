#include <map>
#include <string>
#include <iostream>

class Solution {
public:
	/*
	* @param A: a string
	* @param B: a string
	* @return: a boolean
	*/
	bool Permutation(std::string A, std::string B) {
		// write your code here
		std::map<char, int> component_A;
		std::map<char, int> component_B;
		for (auto i : A) {
			if (component_A.count(i))
				component_A[i]++;
			else component_A[i] = 1;
		}
		for (auto i : B) {
			if (component_B.count(i))
				component_B[i]++;
			else component_B[i] = 1;
		}
		if (A.size() != B.size()) return false;
		for (auto it: A) {

			if (component_B.count(it) && component_B[it] == component_A[it]);
			else return false;
		}
		return true;
	}
};

int main() {
	std::string  A("lliinnttncooddee");
	std::string  B("lintcodelintcode");
	Solution s;
	std::cout << s.Permutation(A, B);
	std::cin.get();
}