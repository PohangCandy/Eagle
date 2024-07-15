#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	vector<string> v;

	while (getline(cin,s))
	{
		v.push_back(s);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}


	return 0;
}