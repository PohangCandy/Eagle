//�־��� ���ڿ����� �ߺ����� �ʰ� ���ӵ� �κ� ���ڿ��� ���Ѵ�.
//�ߺ����� �������� ���տ� �ְ� ����� ��� �� ���̴�.

#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;

	set<string> st;
	string S_part;
	
	//���� �������� ���� �������� �ٿ���.
	//���� ó�� ������ ���ڸ� �����ϴ� ��� �κ� ���ڿ��� ���տ� �ִ´�
	//a,b,a,b,c������ ���������ִ� for��
	//a,ab,aba,abab,ababc ������ ������Ű�� ���� for��
	for (auto i = S.begin(); i != S.end(); i++)
	{
		int index = distance(S.begin(), i);
		S_part.clear();
		while(index != S.size())
		{
			S_part += S[index];
			st.insert(S_part);
			index++;
		}
	}

	//for (auto& a : st)
	//{
	//	cout << a << " ";
	//}

	cout << st.size();

	return 0;
}