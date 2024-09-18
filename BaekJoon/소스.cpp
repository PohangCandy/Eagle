//deque�� �̿��ؼ� �ѹ��� �ذ��� ���� �ִ�.
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> questk;
	deque<int> deq;

	int N;
	cin >> N;
	//�������� ť���� �Ǻ��ϴ� ������ ����
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		questk.push_back(input);
	}

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		//ť�� ���Ҹ� ���� ����
		//���� ���߿� ���� ��Ҹ� back���� pop�ϱ� ���� �ڷ� ����
		if (questk[i] == 0)
		{
			deq.push_back(input);
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input;
		cin >> input;
		//�Է��� ���� ť�� ���Һ��� �ʰ� ���;��ϹǷ� ������ ����
		deq.push_front(input);
		cout << deq.back();
		if (!deq.empty()) 
		{
			deq.pop_back();
			cout << " ";
		}
	}

	return 0;
}