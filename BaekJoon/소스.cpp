//큐 구현하기

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	queue<int> que;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		if (input == "push")
		{
			int num;
			cin >> num;
			que.push(num);
		}
		else if (input == "pop")
		{
			if (que.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if (input == "size")
		{
			cout << que.size() << "\n";
		}
		else if (input == "empty")
		{
			if (que.empty())
			{
				cout << 1 << "\n";
			}
			else cout << 0 << "\n";
		}
		else if (input == "front")
		{
			if (que.empty())
			{
				cout << -1 << "\n";
			}
			else cout << que.front() << "\n";
		}
		else if (input == "back")
		{
			if (que.empty())
			{
				cout << -1 << "\n";
			}
			else cout << que.back() << "\n";
		}
	}

	return 0;
}