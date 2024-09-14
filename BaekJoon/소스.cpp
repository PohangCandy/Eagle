// �л����� ��ȣ ������� ����ְ� �ϱ����� ���α׷�
// �Է¹��� ��ȣ��, ������ ���� ���ڸ� ����(���)�ϰ�
// �ƴ϶�� ���ÿ� �״´�.
// ���ÿ� ���� �ֱٿ� ���� ���� ������ �� ���ڸ� pop�Ѵ�.

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	int order = 1;

	stack<int> line;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		//input�� �Է¹ް� , order�� �ٸ��ٸ� stack�� �ִ� ���鵵 ������ ���Ѵ�.
		//input�� order���, ������ �����Ų �� ���� ������ ������ ž�� �ִ��� �����Ѵ�.
		if (input == order)
		{
			order++;
			while (!line.empty())
			{
				if (line.top() == order)
				{
					line.pop();
					order++;
				}
				else break;
			}
		}
		//input�� order�� �ƴϸ� stack�� �ִ´�.
		else 
		{
			line.push(input);
		}
	}

	if (!line.empty())
	{
		cout << "Sad";
	}
	else cout << "Nice";


	return 0;
}