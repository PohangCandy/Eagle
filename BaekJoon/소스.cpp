//주어진 문자열에서 중복되지 않게 연속된 부분 문자열을 구한다.
//중복되지 않으려면 집합에 넣고 사이즈를 재면 될 것이다.
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