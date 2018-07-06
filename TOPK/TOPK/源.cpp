#include <iostream>
#include <vector>

//#define SWAP(a,b) {a=a^b;b=a^b;a=a^b;}

using namespace std;

int randRangeOf(int a, int b) {
	return a + rand() % (b - a);
}

void SWAP(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int partition(int start, int end, vector<int>& arr) {
	if (start > end || arr.size()==0)
		return -1;
	int index = randRangeOf(start, end);
	SWAP(arr[index], arr[end]);
	int small = start - 1;
	for (int i = start; i < end; i++) {
		if (arr[i] < arr[end]) {
			if (i != small) {
				small++;
				SWAP(arr[i], arr[small]);
			}
		}
	}
	++small;
	SWAP(arr[small], arr[end]);
	return small;
}
int main(void) {

	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> arr(n);

	for(int i=0;i<n;i++)
		cin>>arr[i];
	int start = 0;
	int end = n - 1;
	int m = partition(start, end, arr);
	while (m!=n-k-1 && m!=n-k)
	{
		if (m > n - k - 1) {
			end = m;
		}
		else start = m;
		m = partition(start, end, arr);
	}

	for (int i = n - k; i < n; i++) {
		cout << arr[i] << endl;;
	}

	system("pause");
}