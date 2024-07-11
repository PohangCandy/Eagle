#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	vector<char> vc;

	for (int i = 0; i < T; i++)
	{
		int R;
		cin >> R;

		string S;
		cin >> S;

		for (int j = 0; j < S.size(); j++)
		{
			for (int k = 0; k < R; k++)
			{
				vc.push_back(S[j]);
			}
		}
		for (int j = 0; j < vc.size(); j++)
		{
			cout << vc[j];
		}
		cout << "\n";
		vc.clear();
	}


	return 0;
}
