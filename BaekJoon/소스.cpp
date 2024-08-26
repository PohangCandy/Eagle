#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == b[i]) continue;
			// 사전적으로 더 큰 친구가 뒤로 가야한다.
			// 아스키 코드의 값이 더 클수록 사전적으로 뒤에 배치하는 수가 된다.
			// 더 큰 값은 뒤로 보낸다.
			else return b[i] > a[i];
		}
	}

	// 길이가 길면 뒤로 가야한다.
	// length가 더 큰 값이 뒤로 가야하므로
	// a.length > b.length 를 하면 a가 더 클때 앞에 위치한다.
	// b.length > a.length 를하면 b가 더 클때 a가 앞에 위치한다. 
	return b.length() > a.length();
}

int main()
{
	ios_base::sync_with_stdio(false);
	vector<string> vec;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		vec.push_back(input);
	}

	// 일단 string 배열에 넣어둔다.
	// sort 함수의 세번째 인자를 통해서 
	// 길이로 비교하고, 같다면 아스키 코드로 비교한다.
	// 중복된 단어는 제거한다.

	sort(vec.begin(), vec.end(), compare);

	vec.erase(unique(vec.begin(), vec.end()),vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
		if (i != vec.size() - 1)
		{
			cout << "\n";
		}
	}

	return 0;
}