// �����ϰ� ���μ��� �ɱ�
// �־��� �Ÿ� �߿� ���� ª�� ������ ���Ѵ�.
// 3,2�� �� �Ÿ��� ��� ������ �Ÿ��� 2�� �Ǹ� �ȵȴ�.
// �־��� �Ÿ����� �ִ������� ã�ƾ��Ѵ�.
// ���� ���� ���μ� ��ġ����
// �ִ�������ŭ ���� ���� �����̳ʿ� ���ٸ� �߰��ϰ� �ִٸ� �Ѿ��.
// �ش� �۾��� �����̳� ���� ���� ū ���� ���� ���� ������ �ݺ��Ѵ�.

#include <iostream>
//���μ��� �߰��ϱ����� ���͸� ����
#include <vector>
//�����ϱ����� sort�� ����.
#include <algorithm>
using namespace std;

//�ִ������� ã�� ���� �Լ�
int GCD(int bigger, int smaller)
{
	if (bigger % smaller == 0)
	{
		return smaller;
	}
	else
	{
		return GCD(smaller, bigger % smaller);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> vec;
	vector<int> distance;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	auto it = vec.begin();
	while (it != vec.end())
	{
		distance.push_back(*(it + 1) - (*it));
	}


	return 0;
}