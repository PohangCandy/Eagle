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
	
	//삼중 포문에서 이중 포문으로 줄였다.
	//제일 처음 나오는 문자를 포함하는 모든 부분 문자열을 집합에 넣는다
	//a,b,a,b,c순으로 증가시켜주는 for문
	//a,ab,aba,abab,ababc 순으로 증가시키기 위한 for문
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