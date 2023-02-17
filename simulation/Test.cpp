#include "Test.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v(10);

	for (auto a : v) {
		cout << a << " ";
	}


	return 0;
}