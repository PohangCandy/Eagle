#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //c,c++ ���� �����ֱ�
	cin.tie(NULL); //cin, cout �ڵ� ���� �Ҹ� ����

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