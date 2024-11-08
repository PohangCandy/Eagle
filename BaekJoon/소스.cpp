#include <iostream>
#include <vector>
using namespace std;
//아이디어
// 1. -10~10까지 이루어진 순열 중에 조건을 만족하는 순열을 구한다.
// 2. 주어진 부호 S[i][j] 와 a[i] + ... + a[j]까지의 합을 비교한다.
// 순열에 새로운 수가 들어올 때마다, 해당 수를 중심으로 뒤에 담아져 있는 값들을 조사한다.
// ---> 빽트래킹 문제
// DP vs 빽트래킹
// Dp는 큰 문제를 작은 문제로 쪼갠 결과를 바탕으로 시간복잡도를 줄인다.
// 빽트래킹은 새로운 문제를 해결하기위해 이전 결과를 바탕으로 한다.
// 
//시간복잡도
// 20개의 수로 10개의 순열을 만드는 경우의 수
// 20!/10! -> 약 20^10, 벌써 시간초과가 발생한다.
// 
// 시간복잡도를 줄이는 방법이 있다.
// 빽트래킹
// 새로운 수가 추가 될때마다 조건에 부합하는지 확인한다.
// 조건에 부합하지 않을 경우 return 한다.
// -> 즉 -1이 순열에 들어온 경우 부호 + 와 맞지 않다면 return 되므로
// 시간복잡도가 반으로 준다.
// 10^10
// 그리고 이전에 순열에 담겨진 값들을 부호와 계속해서 비교하며,
// 시간복잡도를 /2씩 줄일 수 있다.
// 총 10개일때 20^10 / 2^10이므로 약 2 * 10^7
// 
// 
//메모리
// 각 요소의 합에 따라 부호를 저장해둘 map[i][j] char * 10 * 10;
// 
//자료형
// 10씩 10번 더한다고 가정하면 1*10 = 100이 최대

vector<int> vec;
int n;
char clue[10][10];

//백트래킹
//새로운 조건을 추가하며
//현재까지의 조건과 합했을 때 부합하는지 테스트
//파라미터
// 백트래킹을 시작할 높이 int h 
bool backTrack(int h)
{
	int sum = 0;
	//가장 밑에 있는 높이까지 조사를 실행
	for (int i = h; i >= 0; i--)
	{
		sum += vec[i];
		if (clue[h][i] == '+' && sum <= 0) return false;
		else if (clue[h][i] == '-' && sum >= 0) return false;
		else if (clue[h][i] == '0' && sum != 0) return false;
	}

	return true;
}

//재귀함수를 그만둘 조건
//	담은 순열의 수가 n이면 exit(0)
//파라미터
// 담고있는 수를 나타낼 int h
void RR(int h)
{
	if (h == n)
	{
		for (auto& a : vec)
		{
			cout << a << " ";
		}
		exit(0);
	}

	for (int i = -10; i <= 10; i++)
	{
		vec.push_back(i);
		if (backTrack(h))
		{
			RR(h + 1);
		}
		vec.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			// 0 0, 1 0, 2 0, 3 0
			//		1 1, 2 1, 3 1
			//			 2 2, 3 2
			//				  3 3
			cin >> clue[j][i];
		}
	}

	RR(0);

	return 0;
}
