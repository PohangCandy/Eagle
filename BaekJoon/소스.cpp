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
#include <deque>
//�ߺ��� �Ÿ��� �����ϰ� ���� ������ �ִ������� ���ϱ����� ������ �̿��Ѵ�.
#include <set>
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
	vector <int> vec;
	vector <int> distance;
	deque <int> gap;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	//������ ���μ� ������ ���Ϳ� ���� �����Ѵ�.
	auto it_v = vec.begin();
	while (it_v + 1 != vec.end())
	{
		distance.push_back(*(it_v + 1) - (*it_v));
		gap.push_back(*(it_v + 1) - (*it_v));
		it_v++;
	}

	// ���� ù��°�� �ι�° ��Ҹ� ������
	// �ִ� ������� ���� ��
	// ù��°, �ι�° ��Ҵ� �����Ѵ�.
	sort(gap.begin(), gap.end());

	while (gap.size() >= 2)
	{
		//int gcd = GCD(gap[0], gap[1]);
		int gcd = GCD(*gap.begin(), *(gap.begin()+1));
		gap.push_back(gcd);
		gap.pop_front();
		gap.pop_front();
	}

	int gcd = gap[0];
	
	//������ �ִ����� �ϳ��� �����ߴ�.
	//���� ���� ���� ���μ�����
	//���� �� ���μ����� ��� ���μ��� ���� ���� ��
	//���� �ִ� ���μ��� �������� ���̸� ���Ѵ�.
	//(�ִ� �Ÿ� - �ּ� �Ÿ� ) / ����  + 1 = �� ����
	int all_branch_num = (((*(vec.end()-1)) - (*vec.begin())) / gcd) + 1;

	cout << all_branch_num - vec.size();

	return 0;
}