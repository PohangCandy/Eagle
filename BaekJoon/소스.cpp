#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int a1, a0;
	int c;
	int n0;

	cin >> a1 >> a0;
	cin >> c;
	cin >> n0;

	// 7n + 7
	// 8n
	// n0 = 1
	// 기울기가 양의 정수이므로 직선형 그래프이다.
	// 즉, 첫 항이 참일 경우 모든 n에서 만족한다.

	//a0, a1이 음수가 될 수 있다는 걸 고려해야한다.
	//a1이 음수인 경우 마찬가지로 첫 항이 참일 경우 참이된다.
	//문제는 a1 > c 이고 a0가 음수인 경우 판별하기 힘들다 
	//a1 = 2, a0 = -1 , c = 1, a0 = 1인 경우 첫항에서만 만족한다.
	//그러므로 모든 n에서 만족하려면 
	// 첫 항이 들어갔을때 크거나 같고,동시에 c가 a1보다 크거나 같아야 한다.


	if (a1 * n0 + a0 <= c * n0 && c >= a1)
	{
		cout << 1;
	}
	else cout << 0;




	return 0;
}