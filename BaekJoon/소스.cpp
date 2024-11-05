#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

float arr[8001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	float N;
	cin >> N;

	vector<int> vec;

	int average;
	int middle;
	int most = 0;
	int range;

	int sum = 0.0f;
	int many = -4000;
	int mini = 4000;
	int num = 0;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);

		sum += input;
		arr[input + 4000]++;
		if (num < arr[input + 4000])
		{
			num = arr[input + 4000];
		}
	}

	sort(vec.begin(), vec.end());
	average = round(sum / N);
	range = vec[N - 1] - vec[0];
	middle = vec[N / 2];
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	//두번째로 작은 최빈값 찾기
	int second = 1;
	for (int i = 0; i < vec.size(); i++)
	{
		if (arr[vec[i] + 4000] == num)
		{
			most = vec[i];
			if (second == 2)
			{
				break;
			}
			second++;
		}
	}

	cout << average << "\n";
	cout << middle << "\n";
	cout << most << "\n";
	cout << range << "\n";


	return 0;
}
