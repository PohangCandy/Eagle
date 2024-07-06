#include <iostream>
using namespace std;

int main()
{
	int A,B,C;
	int sameEye;
	int BiggestEye;

	cin >> A;
	cin >> B;
	cin >> C;

	if (1 <= A && A<= 6 && 1 <= B && B <= 6 && 1 <= C && C <= 6)
	{
		if (A != B && A != C && B != C)
		{
			BiggestEye = A;
			if (B > A && B > C)
			{
				BiggestEye = B;
			}
			else if(C > A && C > B)
			{
				BiggestEye = C;
			}
			cout << BiggestEye * 100;
		}
		else if ((A == B && B != C) || (A == C && A != B))
		{
			sameEye = A;
			cout << 1000 + sameEye * 100;
		}
		else if (A != B && B == C)
		{
			sameEye = B;
			cout << 1000 + sameEye * 100;
		}
		else {
			cout << 10000 + A * 1000;
		}
	}
	
	

	return 0;
}

