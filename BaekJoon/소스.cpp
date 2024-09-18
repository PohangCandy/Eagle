//deque를 이용해서 한번에 해결할 수도 있다.
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> questk;
	deque<int> deq;

	int N;
	cin >> N;
	//스택인지 큐인지 판별하는 데이터 저장
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		questk.push_back(input);
	}

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		//큐의 원소만 덱에 삽입
		//가장 나중에 들어온 요소를 back으로 pop하기 위해 뒤로 삽입
		if (questk[i] == 0)
		{
			deq.push_back(input);
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input;
		cin >> input;
		//입력한 값이 큐의 원소보다 늦게 나와야하므로 앞으로 삽입
		deq.push_front(input);
		cout << deq.back();
		if (!deq.empty()) 
		{
			deq.pop_back();
			cout << " ";
		}
	}

	return 0;
}