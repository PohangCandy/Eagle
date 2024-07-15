#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	vector<string> v;

	while (getline(cin, s))
	{
		v.push_back(s);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}


	string s;
	cin >> s;

	//기존의 배열을 가져와서 지금 있는 단어와 비교하자.


		return 0;
}