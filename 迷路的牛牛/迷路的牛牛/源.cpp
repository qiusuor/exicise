#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	string data;
	cin >> data;
	int count = 0;
	for (auto i : data) {
		if (i == 'L')
			count++;
		else
			count--;
	}
	count %= 4;
	if (count == 0)
		cout << "N";
	else if (count == 1)
		cout << "W";
	else if (count == 2)
		cout << "S";
	else if (count == 3)
		cout << "E";
	else if (count == -1)
		cout << "E"; 
	else if (count == -2)
		cout << "S"; 
	else if (count == -3)
		cout << "W"; 
}