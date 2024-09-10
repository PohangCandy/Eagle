// ������ ��Ƽ��
// ¦�� N�� �� �Ҽ��� ������ ��Ÿ���� ǥ��
// �ش� ������ ���� �Ҽ� ������ ���Ϳ� ��Ƶд�.
// input - prime num�� �� ����� �ε��� ���� 0���� Ȯ���Ѵ�.
// 0�̶�� �̹� ���� ���̰ų� �Ҽ��� �ƴϹǷ� continue�Ѵ�.
// 0�� �ƴ϶�� count�� ������Ű�� �ش� ���� 0���� ������ش�.

#include <iostream>
#include <vector>
using namespace std;

//�����佺�׳׽�
int eratostenas(int num)
{
	int count = 0;
	//0~n ���� ���͸� ������ش�.
	vector<int> vec(num + 1, 0);

	for (int i = 2; i < vec.size(); i++)
	{
		vec[i] = i;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == 0) continue;
		else
		{
			for (int j = i * 2; j < vec.size(); j += i)
			{
				if (vec[j] == 0) continue;
				else  vec[j] = 0;
			}
		}

	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == 0) continue;
		else
		{
			if (vec[num - vec[i]] != 0)
			{
				count++;
				vec[i] = 0;
				vec[num - vec[i]] = 0;
			}
		}
	}

	
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	vector<int> result;
	
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		result.push_back(eratostenas(N));
	}

	for (auto& a : result)
	{
		cout << a << "\n";
	}

	return 0;
}