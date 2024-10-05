#include <iostream>
#include <vector>
using namespace std;
// ���ӵ� �� �߿��� ���� ���� ū �ִ� ����
// 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 
// �ڿ������� �����ؼ� ���� ����� �ȴٸ�
// ���� input�� ������
// �����ָ� ���� ������?

void RR(vector<pair<int, int>> &vec)
{
	for (int i = vec.size() - 1; i > 0; i--)
	{
		// ��, �ڿ��� ������ ���ӵ� ���� �ִ���
		// ������ ���� ���ӵǴ� ���� �� ���� ���Ѵ�.
		if(vec[i].second > 0)
		{
		  // �ڽ��� ���� + �ڿ� ������ ������ ���ӵ� ���� �ִ�
		  vec[i - 1].second = vec[i - 1].first + vec[i].second;
		}
	}
}

// pair<int �Է� ��, int ����ġ ������ �ִ�>�� �������ش�.
vector<pair<int,int>> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		vec.push_back(make_pair(input, input));
	}

	RR(vec);

	//�ִ� �ʱ�ȭ
	int max = 0;
	if (!vec.empty())
	{
		max = vec[0].second;
	}

	for (auto& a : vec)
	{
		if (a.second > max)
		{
			max = a.second;
		}
	}


	// ���������� vector���� ���� ū ���� ����Ѵ�. 
	cout << max;

	return 0;
}