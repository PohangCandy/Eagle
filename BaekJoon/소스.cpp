#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //c,c++ �����ֱ�
	cin.tie(NULL); //cin,cout �ڵ� ���� ���� ����
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