#include <map>
#include <set>
#include <list>
#include <vector>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	/**
	* @param grid a boolean 2D matrix
	* @return an integer
	*/
	int numIslands(vector<vector<bool>>& grid) {
		// Write your code here
		if (grid.empty() || grid[0].empty()) return 0;
		vector<vector<bool>> vis( grid.size(), vector<bool>((grid[0]).size(), false));
		int num=0;
		for (int i=0;i<grid.size();i++)
		{
			for (int j=0;j<grid[0].size();j++)
			{
				if (grid[i][j] == 1 && vis[i][j] == 0) {
					dfs(grid, vis, i, j);
					num++;
				}
			}
		}
		return num;
	}
	void dfs(vector<vector<bool> >& grid, vector<vector<bool>> &vis, int i, int j) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || grid[i][j]==0) return;
		vis[i][j] = true;
		dfs(grid, vis, i, j - 1);
		dfs(grid, vis, i, j +1);
		dfs(grid, vis, i+1, j );
		dfs(grid, vis, i-1, j);
	}
};


int main(void) {
	
	Solution s;
	
	system("pause");
}