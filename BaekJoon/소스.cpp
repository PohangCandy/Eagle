// 아이디어
// 집합을 이용해서 연산 구현하면 될 것 같은데?
// 
// 시간복잡도
//  N까지 반복
//  집합의 find 함수
// 집합에 들어오는 값은 20밖에 안되는데 시간초과가 왜 걸리지?
// 
// 지우거나, 추가한 후에 정렬시키는 작업이 오래걸려서 그런가?
// map, set은 요소를 줄이거나 늘리는 작업을 할 때
// 자동으로 정렬시켜주지만 시간을 많이 잡아먹는다.
// 
// 
// 메모리
//  최대 int * 20
// 자료형
//  최대 20, int

#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	set<int> st;
	set<int> all_st;

	for (int i = 1; i <= 20; i++)
	{
		all_st.insert(i);
	}

	int N;
	cin >> N;
	

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		if (s == "add")
		{
			int input;
			cin >> input;
			st.insert(input);
		}
		else if (s == "remove")
		{
			int input;
			cin >> input;
			st.erase(input);
		}
		else if (s == "check")
		{
			int input;
			cin >> input;
			if (st.find(input) != st.end())
			{
				cout << 1;
				cout << "\n";
			}
			else
			{
				cout << 0;
				cout << "\n";
			}
		}
		else if (s == "toggle")
		{
			int input;
			cin >> input;
			if (st.find(input) != st.end())
			{
				st.erase(input);
			}
			else
			{
				st.insert(input);
			}
		}
		else if (s == "all")
		{
			st.clear();
			st = all_st;
		}
		else if (s == "empty")
		{
			st.clear();
		}
	}

	return 0;
}