#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //c,c++ 끊어주기
	cin.tie(NULL); //cin,cout 자동 버버 출혈 해제
	int A, B;
	vector<int> vAB;


	while(1)
	{
		cin >> A >> B;
		if (A == 0 && B == 0)
		{
			break;
		}
		vAB.push_back(A + B);
	}
	for (int i = 0; i < vAB.size(); i++)
	{
		cout << vAB[i] << "\n";
	}

	return 0;
}