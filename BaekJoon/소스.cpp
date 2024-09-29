#include <iostream>
#include <sstream>
#include <vector>
// ���鹮�ڸ� �ǳʶٰ� ���ڸ� �����ϴ� ���
// 
// �밡�� ���� �ִ����� ���ϱ�
// ��Ŭ���� ȣ���� ���
#include <string>
using namespace std;


int GCD(int s, int b)
{
	if (b >= s)
	{
		if (b % s == 0)
		{
			return s;
		}
		else
		{
			return GCD(s, b % s);
		}
	}
	else
	{
		if (s % b == 0)
		{
			return b;
		}
		else
		{
			return GCD(b, s % b);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// ���� ���� n���� �־������� ������ ��� ���� GCD(Greatest Common Division) �� ���ϱ�
	// �ִ����� ���ϱ�
	// 2 4 2 4  10 10 10  10 20  10
	int t;
	cin >> t;

	vector<int> vec;
	vector<int> gcd;

	while (t > 0)
	{
		vec.clear();

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			vec.push_back(input);
		}
		//1, 000, 000 �� 100�� �־������
		//100!�̹Ƿ� longlong���� ������ش�.
		//�� ���� ������ 10*99/2*1,000,000 �̹Ƿ� 49���̴�??
		long long total = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = i + 1; j < vec.size(); j++)
			{
				total += GCD(vec[i], vec[j]);
			}
		}
		//3 125 15 25
		cout << total;
		if (t > 1)
		{
			cout << "\n";
		}
		t--;
	}
	


	return 0;
}