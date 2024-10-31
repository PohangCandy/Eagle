//아이디어
// 첫 번째로 나보다 앞에 더 큰 수가 얼마나 있는지
// 두번째로 동점자가 내 앞에 얼마나 있는지
// 자신보다 바로 앞에 있는 수의 뒤에 몇명의 동점자가 있는지를 카운트 한다.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N, M;
		cin >> N >> M;

		priority_queue<int> pq;
		vector <int> vec;

		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			vec.push_back(input);
			pq.push(input);
		}

		int bigger = 0;
		for (int j = 0; j < N; j++)
		{
			bigger = pq.top();
			if (vec[M] == pq.top())
			{
				break;
			}
			pq.pop();
		}

		// bigger을 벡터 내부에서 찾아서
		// 몇번째 인덱스인지 찾아본다.


	}

	return 0;
}
