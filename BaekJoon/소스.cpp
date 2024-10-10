#include <iostream>
using namespace std;

// 증가하다가 감소하는 바이토닉 수열을 구한다.
// 1 2 3 4 2 1
// 각 인덱스는 자신이 감소중인지 증가하는 중인지 체크해야한다.
// 감소 중이라면
//  자신보다 작은 값을 만났을때 수열을 더해주고
//	같거나 큰 수를 만나면 수열은 중단된다.
// 증가 중이라면 
//  자신보다 큰 수를 만났을 때 수열을 더해준다.
//
// 그럼 2개의 수열에 대한 totla값을 저장하면 어떨까?
// 다음 수가 증가하는 경우의 total값을 total_increase라하고
// 다음 수가 감소하는 경우의 total값을 total_decrease라고 한다.
// total_increase와 total_decrease의 합이 가장 큰 값을 출력한다.


//시간초과
// 이중포문 10^3^2 = 10^6 , 0.01초
//메모리
// int,pair<int,int> 1000개 = 12kb
//자료형
// 최대 길이 1000 <= int자료형 (2 * 10^9)

int arr[1001];
//increase,decrease
pair<int, int> total[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
		total[i] = { 0,0 };
		for (int j = 1; j < i; j++)

			//이뤄질 수 있는 바이토탈 수열
			// 큰 중 작
			// 20 19 18 10
			// 작 중 큰
			// 10 18 19 20
			// 작 큰 작
			// 8 9 10 9


		{
			//  5
			//  5 2
			//  5 2 4
			//  5 2 4
			//  5 2 4 2
			//  5(0,1) 2(max(왼쪽에 2보다 큰 수의 개수 1,왼쪽에 2보다 작은 수의 개수),max(오른쪽에 2보다 )) 4(1,1) 1(0,0) 5(2,0)
			// 10 6 7
			// 100() 6 70() 80 90

			if (arr[j] > arr[i])
			{
				total[j].second++;
				if (total[j].second > total[i].second)
				{
					total[i].second = total[j].second;
				}
			}
			else if (arr[j] < arr[i])
			{
				total[i].first = total[j].first;
				if (total[j].first > total[i].first)
				{
					total[i].first = total[j].first;
				}
			}
		}

	}

	//increase,decrease에서 모두 자신을 포함시켜서 세었으므로 중복되는 1을 빼준다.
	int maxBitonic = total[0].first + total[0].second - 1;

	for (int i = 1; i < N; i++)
	{
		int t = total[i].first + total[i].second - 1;
		if (t > maxBitonic)
		{
			maxBitonic = t;
		}
	}

	cout << maxBitonic;

	return 0;
}