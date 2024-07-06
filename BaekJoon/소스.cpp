#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long A, B, C;

	cin >> A >> B >> C;
	if (1 <= A <= pow(10, 12) && 1 <= B <= pow(10, 12)&& 1 <= C <= pow(10, 12))
		cout << A + B + C <<endl;


	return 0;
}

