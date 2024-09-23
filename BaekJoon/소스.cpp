// ť �ϳ������ε� �ذ��� �� �ִ� ��������.
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

	// ť�� ���� �տ� �ִ� ���ڸ� �ٽ� ť�� push�Ѵ�
	// K��°�� �ɶ����� ���� ���� ���� pop�ϰ� ����Ѵ�.
	for (int i = 1; i <= N; i++)
	{
		que.push(i);
	}

	cout << "<";
	//que�� ����� 1������ ���߰� ������ش�.
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