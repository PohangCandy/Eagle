#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> vN(N);

	//벡터 초기화
	for (int t = 0; t < vN.size(); t++)
	{
		vN[t] = t + 1;
	}


	int i, j;

	for (int t = 0;t < M; t++)
	{
		cin >> i >> j;
		if (1 <= i <= j <= N)
		{
			int m = vN[i-1];
			vN[i-1] = vN[j-1];
			vN[j-1] = m;
		}
	}

	for (int t = 0; t < vN.size(); t++)
	{
		cout << vN[t] << " ";
	}


	return 0;
}