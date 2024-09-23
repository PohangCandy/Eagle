// 요세푸스 순열
// 원모양으로 둘러 앉은 사람들을 번호에 따라 한명씩 빼는 문제
// 1 - 7 까지 삭제
// 3 6 2(2) 7(5) 5(3) 1(1) 4
// 중간에서 요소를 빼므로 리스트를 써서 작성하고
// 만약 반복자가 리스트의 끝에 위치하면 다시 begin으로 보낸다.

#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	list<int> lst;

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		lst.push_back(i);
	}

	auto it = lst.begin();
	int last = 0;
	int q;
	while (!lst.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			if (it == lst.end())
			{
				it = lst.begin();
				it++;
			}
			else
			{
				it++;
			}
		}
		cout << *it << " ";
		it = lst.erase(it);
	}

	return 0;
}