#include <iostream>
using namespace std;

int main()
{
	long long X,N,a,b;
	long long sum = 0;
	
	cin >> X;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		sum += a * b;
	}
	if (1 <= X <= 1000000000 && 1 <= N <= 100 && 1 <= a <= 1000000 && 1 <= b <= 10)
	{
		if (X == sum)
		{
			cout << "Yes";
		}
		else {
			cout << "No";
		}

	}



	return 0;
}
