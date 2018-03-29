#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int y = k + 1; y <= n; y++) {
		int p = (n + 1) / y;
		sum += p*(y - k);
		if ((p + 1)*y + k <= n)
			sum += n - ((p + 1)*y + k) + 1;
	}
	cout << sum;
	system("pause");

}