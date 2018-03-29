#include <iostream>
#include <stdlib.h>
#include <pthread.h>



using namespace std;

//void sort(int *arr, int n)
//{
//	if (!arr || n <= 0)
//		return;
//	for (int i = 0; i <= n - 2; i++) {
//		for (int j = 1; j <= n - i - 1; j++) {
//			if (arr[j - 1] > arr[j]) {
//				int t = arr[j - 1];
//				arr[j - 1] = arr[j];
//				arr[j] = t;
//			}
//		}
//	}
//}
//int search(int * arr, int start, int end, int target)
//{
//	if (!arr || end - start <= 0)
//		return -1;
//	int mid = (end + start) / 2;
//	while (start < end) {
//		if (arr[mid] == target)
//			return mid;
//		else if (arr[mid] > target)
//			end = mid - 1;
//		else
//			start = mid + 1;
//		mid = (start + end) / 2;
//	}
//	return -1;
//}

class Singleton {
private:
	Singleton() {
		pthread_mutex_init(&mutex, 0);
	}
	static pthread_mutex_t mutex;
	static Singleton *p;

public:
	static Singleton * instanceOf() {
		if (p == NULL) {
			pthread_mutex_lock(&mutex);
			p = new Singleton();
			pthread_mutex_unlock(&mutex);
		}
		return p;
	}
};
pthread_mutex_t Singleton::mutex;
Singleton* Singleton::p = NULL;

int main(void) {

	Singleton *t = Singleton::instanceOf();
	Singleton *tt = Singleton::instanceOf();
	cout << t << endl << tt << endl;
	system("pause");

}