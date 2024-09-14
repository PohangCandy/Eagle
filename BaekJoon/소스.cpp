#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	queue<int> que;
	queue<int> result;

	int N, K;
	cin >> N >> K;
	// 입력 - 1 만큼의 수를 다시 큐에 삽입하고
	// 입력한 인덱스의 요소 제거
	// 모든 요소가 제거 될 때까지 반복
	for (int i = 1; i <= N; i++)
	{
		que.push(i);
	}

	while (!que.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			que.push(que.front());
			que.pop();
		}
		result.push(que.front());
		que.pop();
	}
	cout << "<";

	while (!result.empty())
	{
		cout << result.front();
		result.pop();
		if (result.size() != 0)
		{
			cout << ", ";
		}
	}

	cout << ">";

	return 0;
}