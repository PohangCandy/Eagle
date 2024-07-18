#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	vector<int> Quarter;
	vector<int> Dime;
	vector<int> Nickel;
	vector<int> Penny;
	
	for (int i = 0; i < T; i++)
	{
		int lastMoney;
		cin >> lastMoney;
		
		int Q = lastMoney / 25;
		Quarter.push_back(Q);
		lastMoney -= 25 * Q;

		int D = lastMoney / 10;
		Dime.push_back(D);
		lastMoney -= 10 * Q;

		int N = lastMoney / 5;
		Dime.push_back(N);
		lastMoney -= 5 * N;

		int P = lastMoney / 1;
		Dime.push_back(P);
		lastMoney -= 1 * P;
	}

	for (int i = 0; i < T; i++)
	{
		cout << Quarter[i] << " " << Dime[i] << " " << Nickel[i] << " " << Penny[i];
	}

	return 0;
}