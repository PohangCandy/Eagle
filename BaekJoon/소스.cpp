//원형으로 배치된 풍선을 쪽지 순서대로 터트리기

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	deque<int> deq;
	vector<int> paper;
	vector<int> result;

	int N;
	cin >> N;
	// 덱을 이용해서 남아있는 풍선의 번호를 표현한다.
	// 2 ~ N까지 저장되어있는 덱을 만든다.
	for (int i = 2; i <= N; i++)
	{
		deq.push_back(i);
	}
	//항상 첫 번째 풍선이 먼저 터진다.
	result.push_back(1);

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		paper.push_back(input);
	}

	// 입력을 받는 횟수
	// 풍선을 터트리는 횟수는 총 n번이다.
	// 입력 순서대로 들어가지 않는다.
	// 입력한 값은 각 풍선에 적혀있는 다음 풍선 지정 번호이다.
	int index = 1;
	while (1)
	{
		if (deq.empty()) break;
		//vec는 0부터 시작하므로 -1해준다.
		int next = paper[index-1];

		if (next > 0)
		{
			// input = 3
			// 2 3 4 5
			// 5 2 3 "4"
			while (next != 0)
			{
				deq.push_back(deq.front());
				deq.pop_front();
				//cout << "move front_deq " << deq.back() << "to back" << "\n";
				next--;
			}
			result.push_back(deq.back());
			//cout << "push back_deq " << deq.back() << "to vec" << "\n";
			index = deq.back();
			deq.pop_back();
		}
		else if (next < 0)
		{
			// input = -3
			// 2 3 4 5
			// "3" 4 5 2
			while (next != 0)
			{
				deq.push_front(deq.back());
				deq.pop_back();
				//cout << "move back_deq " << deq.front() << "to front" << "\n";
				next++;
			}
			result.push_back(deq.front());
			//cout << "push front_deq " << deq.front() << "to vec" << "\n";
			index = deq.front();
			deq.pop_front();
		}
	}

	for (auto& a : result)
	{
		cout << a << " ";
	}

	return 0;
}