// 큐를 사용해서 입력받은 문장의 front를 빼면서
// 순차적으로 접미사를 벡터에 담는다.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	queue<char> que;
	vector<string> vec;

	string S;
	cin >> S;

	for (auto& a : S)
	{
		que.push(a);
	}

	while (!que.empty())
	{
		string str;
		while (!que.empty())
		{
			str += que.front();
			que.pop();
		}
		vec.push_back(str);
		for (auto& a : str)
		{
			que.push(a);
		}
		que.pop();
	}

	sort(vec.begin(), vec.end());

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
