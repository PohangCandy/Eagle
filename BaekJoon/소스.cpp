// 큐 하나만을로도 해결할 수 있는 문제였다.
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	queue<int> que;

	int N, K;
	cin >> N >> K;

	// 큐의 가장 앞에 있는 숫자를 다시 큐에 push한다
	// K번째가 될때마다 가장 앞의 값을 pop하고 출력한다.
	for (int i = 1; i <= N; i++)
	{
		que.push(i);
	}

	cout << "<";
	//que의 사이즈가 1남으면 멈추고 출력해준다.
	while (que.size() > 1)
	{
		for (int i = 1; i < K; i++)
		{
			que.push(que.front());
			que.pop();
		}
		cout << que.front() <<", ";
		que.pop();
	}

	if (!que.empty())
	{
		cout << que.front() << ">";
	}

	return 0;
}