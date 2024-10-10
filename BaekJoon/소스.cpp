#include <iostream>
using namespace std;
//가장 긴 감소하는 부분 수열의 길이를 구한다.
//그냥 자기보다 큰 수가 있으면 count를 증가시켜서
//자신의 인덱스에 해당하는 배열에 저장해두면 되지 않을까?


//시간제한
// 최대 N은 10^3이므로 이중 포문에서 걸릴 수 있는 최대 시간
// 10^6
//   
//메모리 
// 4바이트 int형 1000개 저장하는 배열 2개, 8kb
//
//자료형
//최대 길이 1000 < 2*10^9이므로 int형으로 작성 

int arr[1001];
int Count[1001];

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
		Count[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[j] > arr[i])
			{
				if (Count[j] + 1 > Count[i])
				{
					Count[i] = Count[j] + 1;
				}
			}
		}
	}

	int maxCount = Count[1];
	for (int i = 1; i <= N; i++)
	{
		if (Count[i] > maxCount)
		{
			maxCount = Count[i];
		}
	}

	cout << maxCount;

	return 0;
}