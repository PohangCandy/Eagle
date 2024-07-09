#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //c,c++ 연결 끊어주기
	cin.tie(NULL); //cin, cout 자동 버퍼 소멸 해제

	int A, B;
	vector<int>  vAB;

	while (cin >> A >> B)
	{
		vAB.push_back(A + B);
	}

	for(int i = 0; i < vAB.size(); i++)
	{
		cout << vAB[i] << "\n";
	}

	return 0;
}