#include <iostream>

using namespace std;

int binarySearch2(int start, int end, int* arr, int target) {
	if (end < start || arr == NULL)
		return -1;
	//int count = 0;
	int mid = start + (end - start) / 2;
	while (start <= end) {
		//cout << count++ << endl;
		if (arr[mid] == target)
		{
			//cout << count++ << endl;
			return mid;
		}
		else if (arr[mid] > target)
		{
			//cout << count++ << endl;
			end = mid - 1;
		}
		else
			start = mid + 1;
		mid = start + (end - start) / 2;
	}
	return -1;
}

int binarySearch1(int * arr, int n, int length)
{
	int low = 0;
	int high = length;
	//int count = 0;
	while (low < high)
	{
		//cout << count++ << endl;
		int mid = (low + high) / 2;
		if (arr[mid] == n)
		{
			//cout << count++ << endl;
			return mid;
		}
		else if (arr[mid] < n)
		{
			//cout << count++ << endl;
			low = mid + 1;
		}
		else //arr[mid]>n
			high = mid;
	}
	return -1;
}


int main(void) {
	int arr[10]{ 2,5,9,55,66,67,69,71,75,80 };

	cout << binarySearch2(0, 9, arr, 67);
	system("pause");
}