//queuestack
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> questack;
	vector<int> result;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		questack.push_back(input);
	}

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		result.push_back(input);
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input;
		cin >> input;
		for (int j = 0; j < questack.size(); j++)
		{
			if (questack[j] == 0)
			{
				int temp = result[j];
				result[j] = input;
				input = temp;
			}
			else
				continue;
		}
		cout << input << " ";
	}
	// 스택에서 팝하면 최신게나감
	// 큐에서 팝하면 오래된게 나감
	

	return 0;
}