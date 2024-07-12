#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	vector<char> vs1,vs2;
	int v1,v2;
	bool word_end = false;
	getline(cin, s);

	//cout << s.size() << endl;

	for (int A = 0; A < s.size(); A++)
	{
		//������ �ְų� ������ �ܾ��� ��� ���ݱ��� ���� ���ڿ� �Ųٷ� ������
		if (s[A] == ' ')
		{
			reverse(vs1.begin(), vs1.end());
			word_end = true;
		}
		if (A == s.size() - 1)
		{
			vs2.push_back(s[A]);
			reverse(vs2.begin(), vs2.end());
			break;
		}

		//������ �������� ���Ϳ� �Է¹��� ���� ���� ���
		if (word_end == false)
		{
			vs1.push_back(s[A]);
		}
		else
		{
			if (s[A] != ' ')
			{
				vs2.push_back(s[A]);
			}
			
		}
	}
	//for (auto& A : vs1)
	//{
	//	cout << A;
	//}
	//cout << endl;
	//for (auto& A : vs2)
	//{
	//	cout << A;
	//}
	//cout << endl;
	v1 = 0;
	v2 = 0;
	//�� ������ ������ int�� ��ȯ�ؼ� ����� �� �� ū ���� ���� ����Ѵ�.
	for (int A = 0; A < vs1.size(); A++)
	{
		if(A == 0)
		{
			int p = int(vs1[0]) - int('0'); //ASCII�ڵ� ���� ���� ���� ���
			v1 += p * 100;
			//cout << v1 <<endl;
		}
		if (A == 1)
		{
			int p = int(vs1[1]) - int('0');
			v1 += p * 10;
			//cout << v1 << endl;
		}
		if (A == 2)
		{
			int p = int(vs1[2]) - int('0');
			v1 += p * 1;
			//cout << v1 << endl;
		}
	}
	for (int A = 0; A < vs2.size(); A++)
	{
		if (A == 0)
		{
			int p = int(vs2[0]) - int('0'); //ASCII�ڵ� ���� ���� ���� ���
			v2 += p * 100;
		}
		if (A == 1)
		{
			int p = int(vs2[1]) - int('0');
			v2 += p * 10;
		}
		if (A == 2)
		{
			int p = int(vs2[2]) - int('0');
			v2 += p * 1;
		}
	}

	if (v1 > v2)
	{
		cout << v1;
	}
	else
	{
		cout << v2;
	}




	return 0;
}