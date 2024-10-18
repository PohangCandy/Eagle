#include <iostream>
using namespace std;

// 리모컨 버튼 최소로 눌러서 원하는 채널 N으로 이동하기
// 고장난 버튼을 제거하고 최소 이동 경로 찾기
// 시작 지점은 100

//  80000
//	77777	   (5)
//	 2223	(2223)

//1. 입력받은 N에 남아있는 숫자 버튼을 가지고 최대한 가까이 접근하기
//2. 위아래 버튼으로 입력받은 수에 접근하기

// 이동하고자 하는 채널이 n이라면
// 1. 위아래버튼으로 접근하는 경우의 수는 n - 100이다.
// 
// 2. 최대한 가까이 접근한 수가 s일때
// 위아래 버튼을 사용하는 경우의 수는 n-s이다.
//
// max(n - s + s의 자릿수, n - 100)을 한 결과가
// 최종 답이 된다.

// n > s인 경우
// 더 큰 자릿수가 되거나, 같은 자릿수 중에 나올 수 있는 가장 최소한으로 큰 값이 앞자리에 나온다.

//구해야하는 값은 두가지이다.
// 입력받은 수에 가장 근접한 두 수를 구한다.
// 하나의 수는 입력받은 값보다 작은 수 중에서 구한다.
// 하나의 수는 입력받은 값보다 큰 수 중에서 구한다.

//리모컨에 있는 버튼의 고장 유무를 나타낸다. 
bool remocon[10];

int result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//기존의 리모컨은 모두 작동가능
	for (auto& a : remocon)
	{
		a = true;
	}

	int N;
	cin >> N;
	
	int numOfBrakedKeyboard;
	cin >> numOfBrakedKeyboard;
	for (int i = 0; i < numOfBrakedKeyboard; i++)
	{
		int remoconNum;
		cin >> remoconNum;
		remocon[remoconNum] = false;
	}

	//100번 채널에서 시작했을때
	//위,아래로 움직이는 버튼만 가지고 찾는 경우의 수
	result = abs(N - 100);

	//N보다 적은 값 중 리모컨으로 접근 할 수 있는 최댓값
	for(int i = N; i >= 0; i--)
	{
		int c = i;
		//예외처리 필요
		// i == 0이고 0이 고장난 경우
		// 즉,N 아래에서 접근 할 수 있는 수가 없는 경우
		// 즉시 break를 걸어준다.
		// 0이 고장나지 않았을 경우
		// 
		if (c == 0)
		{
			if (remocon[0] == false)
			{
				break;
			}
			// 접근 가능한 수가 0이라면
			// 0에서 위아래로 이동하는 경우와
			// 현재 결과를 비교해준다.
			else
			{
				//0에서 이동하는데 걸리는 위아래 버튼 N번
				//0을 입력하므로 +1
				result = min(result, N + 1);
			}
		}
		while (c != 0)
		{
			//고장난 리모컨이 아닐경우 계속해서 누른다.
			if (remocon[c % 10])
			{
				c /= 10;
			}
			else
			{
				break;
			}
		}

		//고장난 리모컨일 경우
		if (c != 0)
		{
			continue;
		}
		//모든 리모컨번호가 살아있는 번호인 경우
		else
		{
			//자릿수를 구해준다.
			int count = 0;
			while (i != 0)
			{
				i /= 10;
				count++;
			}

			//자릿수와 위아래 이돟하는 경우의 수를 더한 합과
			//이전 결과 중 더 작은 값으로 결정한다.
			result = min(result, abs(N - i) + count);
			//가장 첫번째로 구한 값이 가장 근접한 값이므로
			//break를 통해 for문을 빠져나와도 상관없다.
			break;
		}
	}

	//N보다 큰 값 중 리모컨으로 접근 할 수 있는 최댓값
	for (int i = N; i <= 500000; i++)
	{
		int c = i;
		//예외처리 필요
		// i == 500000이고 0
		// 즉,N 아래에서 접근 할 수 있는 수가 없는 경우
		// 즉시 break를 걸어준다.
		// 0이 고장나지 않았을 경우
		// 
		if (c == 0)
		{
			if (remocon[0] == false)
			{
				break;
			}
			// 접근 가능한 수가 0이라면
			// 0에서 위아래로 이동하는 경우와
			// 현재 결과를 비교해준다.
			else
			{
				//0에서 이동하는데 걸리는 위아래 버튼 N번
				//0을 입력하므로 +1
				result = min(result, N + 1);
			}
		}
		while (c != 0)
		{
			//고장난 리모컨이 아닐경우 계속해서 누른다.
			if (remocon[c % 10])
			{
				c /= 10;
			}
			else
			{
				break;
			}
		}

		//고장난 리모컨일 경우
		if (c != 0)
		{
			continue;
		}
		//모든 리모컨번호가 살아있는 번호인 경우
		else
		{
			//자릿수를 구해준다.
			int count = 0;
			while (i != 0)
			{
				i /= 10;
				count++;
			}

			//자릿수와 위아래 이돟하는 경우의 수를 더한 합과
			//이전 결과 중 더 작은 값으로 결정한다.
			result = min(result, abs(N - i) + count);
			//가장 첫번째로 구한 값이 가장 근접한 값이므로
			//break를 통해 for문을 빠져나와도 상관없다.
			break;
		}
	}

	return 0;
}