#include <iostream>
using namespace std;

//시간초과
// 이중포문 2번
// (10^3)^2 * 2 = 2 * 10^6, 대략 0.02초
//메모리
// int형 1000개 배열, pait형 int쌍으로 2000개
// 4byte * 3000 = 12kb
//자료형
// 최대 길이 1000 < 2 * 10^9 
// int형으로 충분하다.

int arr[1001];
pair<int, int> p[1001];

//왼쪽
//1(0) 5(1) 2(1) 1(0) 4(2) 3(2) 4(3) 5(4) 2(1) 1(0)

//오른쪽
//1(0) 5(4) 2(1) 1(0) 4(3) 3(2) 4(2) 5(2) 2(1) 1(0)

//최대는 {1, 2, 3, 4, 5(4,2), 2, 1}이므로 자신을 수열에 포함해서 7이된다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 왼쪽에 있을 수열은 나보다 작은 수 중에 최대 수열의 크기
	// 오른쪽 어떻게 하는데 뻑킹
	// 오른쪽은 차라리 입력을 다 받은 후에 값을 정리하는게 낫지 않을까?

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
		//왼쪽에 들어갈 증가하는 수열은 입력과 동시에 정리할 수 있다.
		//자신이 가진 왼쪽 수열이 5개라면
		//arr[5]부턴 조사할 필요없다.
		p[i].first = 0;
		for (int j = i; j >= p[i].first; j--)
		{
			//arr[0]엔 값이 없으므로 패스
			if (j == 0)
			{
				continue;
			}

			if (arr[i] > arr[j])
			{
				// 만약 자신보다 작은 수를 만났는데
				// 가지고 있는 수열의 개수가 자신과 같거나
				// 더 클 경우
				// 해당 수열을 포함하기위해
				// p[j].first를 더하고
				// 해당 수도 더하기위해서 +1을 한다.
				if (p[j].first >= p[i].first)
				{
					p[i].first = p[j].first + 1;
				}
			}
		}
	}

	// 오른쪽 수열에 대해서도 정리한다.
	// 크기가 N이라면, N - 1요소부터 시작해서 자신의 오른편에 있는 값 중
	// 자신보다 작고 가장 큰 수열을 가지는 친구를 더한다.
	for (int i = N - 1; i >= 1; i--)
	{
		p[i].second = 0;
		for (int j = i; j <= N - p[i].second; j++)
		{
			if (arr[i] > arr[j])
			{
				if (p[j].second >= p[i].second)
				{
					p[i].second = p[j].second + 1;
				}
			}
		}
	}

	int result = p[1].first + p[1].second;
	for (int i = 1; i <= N; i++)
	{
		int m = p[i].first + p[i].second;
		if (m > result)
		{
			result = m;
		}
	}

	//수열에 자기자신을 포함해서 +1을 한다.
	cout << result + 1;

	return 0;
}