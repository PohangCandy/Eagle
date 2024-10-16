#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//아홉 난쟁이중 일곱명의 난쟁이 합이 100
//두명의 난쟁이를 제외했을때 합이 100이 되는지 조사한다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> hobit;

	for (int i = 0; i < 9; i++)
	{
		int input;
		cin >> input;
		hobit.push_back(input);
	}

	sort(hobit.begin(), hobit.end());

	//for (int i = 0; i < hobit.size(); i++)
	//{
	//	cout << hobit[i] << "\n";
	//}


	int fake_one = 0;
	int fake_two = 0;

	for (int i = 0; i < hobit.size(); i++)
	{
		int total = 0;

		for (int j = i + 1; j < hobit.size(); j++)
		{
			total = 0;
			for (int k = 0; k < hobit.size(); k++)
			{
				if (k == i || k == j)
				{
					continue;
				}
				else {
					total += hobit[k];
				}
			}
			if (total == 100)
			{
				fake_one = j;
				break;
			}
		}

		if (total == 100)
		{
			fake_two = i;
			break;
		}
	}

	for (int i = 0; i < hobit.size(); i++)
	{
		if (i == fake_one || i == fake_two)
		{
			continue;
		}
		else {
			cout << hobit[i] << "\n";
		}
	}


	return 0;
}