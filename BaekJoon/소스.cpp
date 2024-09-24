// �ð������� �����Ƿ� ���� �������� ���� �� ����.
// �Է� ���� ���� ������ �Է¹��� ������ �� ū ��� �ش� ���� ��ū���� �ȴ�.
// ��ū���� ã�� ���� ���� �ε��� ��ȣ�� ���ÿ� �����صΰ�
// ���� �Է°��� ���ؼ� ��ū���� ã�Ҵٸ�
// pop���� ���ÿ� �ִ� �ε��� ���� ���ش�.
// ������ �������� ���� ���ϴ�
// �Է� ���� ���ÿ� �ִ� �ε��� ������ �۴ٸ� break�ϰ�
// stack�� push �Ѵ�.
// ��� �Է��� ���� �Ŀ��� ���ÿ� �����ִ� ������
// ��ū���� -1�� �������ش�.

#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int res[1000001];
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
		// ������ �� ������,
		// ���� �Է¹��� ���� 
		// ���ÿ� �ִ� ���� ���Ѵ�.
		while (!stk.empty())
		{
			//���� �Է°��� ������ top�� ����Ű�� �ε��� ������ ũ�ٸ�
			//�Է°��� �ش� ���� ��ū ���� �ȴ�.
			if (input > arr[stk.top()])
			{
				res[stk.top()] = input;
				stk.pop();
			}
			//�۴ٸ� �Է°��� �ε����� ���ÿ� push�Ѵ�.
			else
			{
				break;
			}
		}
		stk.push(i);
	}

	//��� �Է��� ��ģ �Ŀ� ���ÿ� �����ִ� ������ -1�� ����
	while (!stk.empty())
	{
		res[stk.top()] = -1;
		stk.pop();
	}

	for (int i = 0; i < N; i++)
	{
		cout << res[i] << " ";
	}

	return 0;
}