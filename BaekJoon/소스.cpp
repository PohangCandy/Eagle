#include <iostream>
#include <algorithm>
using namespace std;

struct  position
{
	int x, y;
};

bool compare(position a,position b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}

	return a.x < b.x;
}

int main()
{
	position arr[100001];
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr, arr+N, compare);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].x << " " << arr[i].y << "\n";
	}


	return 0;
}
