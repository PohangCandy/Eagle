#include <iostream>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false); //C 와 C++ 비동기 처리
	cin.tie(nullptr);// cin과 cout 연결 끊기, 버퍼 나중에 한번에 처리 방식

	int T,A,B;
	int* P;
	cin >> T;
	P = new int[T];
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		P[i] = A + B;
	}
	if (T <= 1000000 && 1 <= A <= 1000 && 1 <= B <= 1000)
	{
		for (int i = 0; i < T; i++)
		{
			cout << P[i] << "\n"; //endl은 버퍼를 즉시 출력하므로 \n을 써서 버퍼 출력막기
		}
	}


	return 0;
}
