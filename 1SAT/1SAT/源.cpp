#include <iostream>
#include <set>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;


class OneSat {
public:
	string CNF;
	OneSat(string CNF) {
		this->CNF = CNF;
	}
	bool solve() {
		set<string> appeared;
		string source = "I am a  stduent,you are teacher!";
		vector<string> destination;
		boost::split(destination, source, boost::is_any_of(" ,!"), boost::token_compress_on);//如果此处使用boost::token_compress_off
		vector<string>::iterator it;
		

	}
};
int main(void) {
	OneSat solution("");
	solution.solve();
	system("pause");
}