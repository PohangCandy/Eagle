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
	//문자열의 길이를 계속 늘리기위해
	//삼중 포문을 써본다.
	
	for (int i = 1; i <= S.size(); i++)
	{
		auto it = S.begin();

		//string 클래스 반복자가 튕긴다고 쥰나 오류나는데 뭐지?
		while (it != S.end())
		{
			S_part.clear();
			//마지막 요소일때 범위 초과가 일어나는 것 같다.
			//for문에 조건을 추가했는데도 오류가 난다.
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