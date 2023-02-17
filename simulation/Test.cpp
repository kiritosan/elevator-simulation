#include "Test.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v(10);

	v.push_back(3);
	vector<int> list[10];
	
	list[1].push_back(1);
	list[1].push_back(2);
	list[2].push_back(1);
	list[3].push_back(1);
	
	for (int i=0; i<list[1].size(); i++)
	{
		cout << list[1][i] << endl;
	}


	return 0;
}