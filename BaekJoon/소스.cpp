#include <iostream>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false); //C �� C++ �񵿱� ó��
	cin.tie(nullptr);// cin�� cout ���� ����, ���� ���߿� �ѹ��� ó�� ���

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
			cout << P[i] << "\n"; //endl�� ���۸� ��� ����ϹǷ� \n�� �Ἥ ���� ��¸���
		}
	}


	return 0;
}
