#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[500001] = {0};
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int average;
	int middle;
	int most;
	int range;

	int N;
	cin >> N;

	float sum = 0;
	int maxi = -4000;
	int mini = 4000;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr[input]++;
		vec.push_back(N);
		sum += input;

		mini = min(mini, input);
		maxi = max(maxi, input);
	}

	sort(vec.begin(), vec.end());

	average = round(sum / N);
	middle = vec[(N - 1) / 2];

	int count = 1;
	vector<int> v;
	for (int i = 1; i <= 500000; i++)
	{
		if (arr[i] > count)
		{
			v.clear();
			v.push_back(i);
		}
		else if (arr[i] == count)
		{
			v.push_back(i);
		}
	}
	if (v.size() > 1)
	{
		most = v[1];
	}
	else
	{
		most = v[0];
	}
	range = maxi - mini;
	
	cout << average << "\n";
	cout << middle << "\n";
	cout << most << "\n";
	cout << range;

	return 0;
}
