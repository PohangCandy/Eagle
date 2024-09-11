// 창문여닫기가 진행되면서 자신의 약수를 만나면 값이 반전된다.
// 1은 모든 수의 약수이므로 모든 창문은 열린 채로 시작하고
// 약수의 개수가 홀수 개인 수가 최종적으로 1이 된다.
// 약수의 개수가 홀수 개인 수는 완전 제곱수이다.
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//범위내의 완전 제곱수의 개수를 찾으면 된다.
	int N;
	cin >> N;

	int count = 0;
	for (int i = 1; i * i <= N; i++)
	{
		count++;
	}
	cout << count;

	return 0;
}