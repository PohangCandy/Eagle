#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	int x, y;
	vector<int> first;
	for (int i = -999; i <= 999; i++)
	{
		for (int j = -999; j <= 999; j++)
		{
			if ((a  * i) + (b  * j) == c)
			{
				first.push_back(i);
				first.push_back(j);
			}
		}
	}

	for (int i = 0; i < first.size(); i++)
	{
		if (i % 2 == 0)
		{
			x = first[i];
			y = first[i + 1];
			if ((d * x) + (e * y) == f)
			{
				break;
			}
		}
	}

	cout << x << " " << y;

	//(a+d)x + (b+e)y = c+f
	//ax + by = c
	

	return 0;
}