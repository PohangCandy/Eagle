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
	//���ڿ��� ���̸� ��� �ø�������
	//���� ������ �ẻ��.
	
	for (int i = 1; i <= S.size(); i++)
	{
		auto it = S.begin();

		//string Ŭ���� �ݺ��ڰ� ƨ��ٰ� �볪 �������µ� ����?
		while (it != S.end())
		{
			S_part.clear();
			//������ ����϶� ���� �ʰ��� �Ͼ�� �� ����.
			//for���� ������ �߰��ߴµ��� ������ ����.
			for (auto j = it; j != it + i && j != S.end(); j++)
			{
				S_part += *j;
			}
			st.insert(S_part);
			it++;
		}
	}

	for (auto& a : st)
	{
		cout << a << " ";
	}

	return 0;
}