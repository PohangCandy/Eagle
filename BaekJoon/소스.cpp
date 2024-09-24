// count �Լ��� ����ؼ� �Է¹��� ��Ҹ� �迭�� �����ص� ��
// ���� �ֱٿ� ���� ���� �ڽ��� �������� ũ�� �ش� ���� result�� ���������ش�.

#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
//���� ����
int num[1000001] {0};
//�ڽź��� ���� �� ����
int res[1000001];

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
		//�ε��� ��ȣ�� ������ ����
		num[input] += 1;
	}

	stack<int> stk;

	for (int i = 0; i < N; i++)
	{
		// �ε��� ��ȣ�� ���ÿ� push�ϸ鼭 
		// num[stk.top()]�� num[arr[i]]�� ���ؼ�
		// ������ ž�� �ִ� ���� ������ �� �۴ٸ�
		// res[stk.top()] = arr[i]�� �ȴ�.
		//������ �������� �ش� �۾��� �ݺ��Ѵ�.
		while (!stk.empty())
		{
			// ������ �ε��� ��ȣ�� 0���� �����ϹǷ�
			// num�� �ε����� ���߱� ���� +1�� ���ش�.
			if (num[arr[i]] > num[arr[stk.top()]])
			{
				res[stk.top()] = arr[i];
				stk.pop();
			}
			else
			{
				break;
			}
		}

		stk.push(i);
	}

	//���ÿ� �����ִ� ģ���鿡�� -1�� �ش�.
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