#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int a, b, c;
	vector <int> input;
	cin >> a >> b >> c;
	input.push_back(a);
	input.push_back(b);
	input.push_back(c);

	// �ﰢ���� �����Ϸ��� ���� �� ���� ���̰� ������ �κ��� ������ �պ��� ��ų� ������ �ȵȴ�.
	// ���� �� ���� ���̸� ã�´�.
	// �ش� ���� ������ �κ��� ������ �հ� ���Ѵ�.
	// ���� �� ���� ���̰� �� ��ų� ���ٸ� �ش� ���� �κ��� ������ �� - 1�� ��ü�Ѵ�. 

	int max = 0;
	int left = 0;
	for (auto &i:input)
	{
		if (i > max)
		{
			left += max;
			max = i;
		}
		else
		{
			left += i;
		}
	}

	if (max >= left)
	{
		cout << left + left - 1;
	}
	else
	{
		cout << left + max;
	}



	return 0;
}