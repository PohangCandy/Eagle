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
	// �Է� - 1 ��ŭ�� ���� �ٽ� ť�� �����ϰ�
	// �Է��� �ε����� ��� ����
	// ��� ��Ұ� ���� �� ������ �ݺ�
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