#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>


using namespace std;

int main(int prameter, char **args) {
	
	int userNum;
	cin >> userNum;
	cin.get();
	vector<vector<int>> *likeLevel=new vector<vector<int>>(100, vector<int>());
	int temp;
	
	for (int i = 0; i < userNum; i++)
	{
		cin >> temp;
		if (temp >= 0) {
			if (temp > (*likeLevel).size() - 1)
				(*likeLevel).resize((*likeLevel).size() << 1);
			(*likeLevel)[temp].push_back(i + 1);
		}
	}
	cin.get();
	int queryTime;
	cin >> queryTime;
	cin.get();

	int ** queryData = new int *[queryTime];
	for (int i = 0; i < queryTime; i++)
	{
		*(queryData + i) = new int[3];
	}

	for (int i = 0; i < queryTime; i++)
	{
		cin >> temp;
		queryData[i][0] = temp;
		cin >> temp;
		queryData[i][1] = temp;
		cin >> temp;
		queryData[i][2] = temp;
		cin.get();
	}



	vector<int> *result = new vector<int>(queryTime, 0);


	int leftLocation;
	int rightLocation;
	int left;
	int right;
	int mid;

	for (int i = 0; i < queryTime; i++) {
		leftLocation = 0;
		rightLocation = (*likeLevel)[queryData[i][2]].size() - 1;


		left = 0;
		right = (*likeLevel)[queryData[i][2]].size() - 1;
		mid = (left + right) / 2;
		while (left <= right) {
			if (queryData[i][0] > (*likeLevel)[queryData[i][2]][mid]) {
				left = mid + 1;
			}
			else if (queryData[i][0] < (*likeLevel)[queryData[i][2]][mid]) {
				right = mid - 1;
			}
			else break;
			mid = (left + right) / 2;
		}

		leftLocation = mid;
		if (queryData[i][0] == (*likeLevel)[queryData[i][2]][mid])
			leftLocation = mid - 1;


		left = 0;
		right = (*likeLevel)[queryData[i][2]].size() - 1;
		mid = (left + right) / 2;
		while (left <= right) {
			if (queryData[i][1] > (*likeLevel)[queryData[i][2]][mid]) {
				left = mid + 1;
			}
			else if (queryData[i][1] < (*likeLevel)[queryData[i][2]][mid]) {
				right = mid - 1;
			}
			else break;
			mid = (left + right) / 2;
		}
		rightLocation = mid + 1;
		if (queryData[i][1] == (*likeLevel)[queryData[i][2]][mid])
			rightLocation = mid;


		(*result)[i] = rightLocation - leftLocation - 1;

	}
	for (int i = 0; i < queryTime; i++)
	{
		cout << (*result)[i] << endl;
	}

	system("pause");
	return 0;
}