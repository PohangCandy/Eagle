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

	for (int i = 0; i < S.size(); i++)
	{
		auto it = S.begin();
		while (it  + i != S.end())
		{
			S_part.clear();
			for (auto j = it; j <= it + i; j++)
			{
				S_part += *j;
			}
			st.insert(S_part);
			it++;
		}
	}

	cout << st.size();

	return 0;
}