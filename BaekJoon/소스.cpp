#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//���� ���̰� 333,334�� ���� �ʴ´�.
	//8���� �̹Ƿ� 2^1,000,000 = 10^300,000�̹Ƿ�
	//string���� �Է��� �޾��ش�.

	string input;
	cin >> input;

	deque<int> res;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] - '0' >= 4)
		{
			res.push_back(1);
			input[i] -= 4;
		}
		else
		{
			res.push_back(0);
		}
		if (input[i] - '0' >= 2)
		{
			res.push_back(1);
			input[i] -= 2;
		}
		else
		{
			res.push_back(0);
		}
		if (input[i] - '0' >= 1)
		{
			res.push_back(1);
			input[i] -= 1;
		}
		else
		{
			res.push_back(0);
		}
	}

	while (res.front() == 0)
	{
		res.pop_front();
	}

	for (auto& a : res)
	{
		cout << a;
	}

	return 0;
}