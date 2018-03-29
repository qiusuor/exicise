#include <iostream>
#include <hash_map>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <hash_set>
#include <string>


class LFUCache {
public:
	/*
	* @param capacity: An integer
	*/LFUCache(int capacity) {
	
	// do intialization if necessary
}

	  /*
	  * @param key: An integer
	  * @param value: An integer
	  * @return: nothing
	  */
	  void set(int key, int value) {
		  // write your code here
	  }

	  /*
	  * @param key: An integer
	  * @return: An integer
	  */
	  int get(int key) {
		  // write your code here
	  }
protected:
	struct node
	{
		int value;
		int count;
		
	};
private:
	hash_map<int,
};