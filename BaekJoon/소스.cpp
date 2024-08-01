#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int a, b, c;
	vector <int> input;
	cin >> a >> b >> c;
	input.push_back(a);
	input.push_back(b);
	input.push_back(c);

	// 삼각형을 만족하려면 가장 긴 변의 길이가 나머지 두변의 길이의 합보다 길거나 같으면 안된다.
	// 가장 긴 변의 길이를 찾는다.
	// 해당 값을 나머지 두변의 길이의 합과 비교한다.
	// 가장 긴 변의 길이가 더 길거나 같다면 해당 값을 두변의 길이의 합 - 1로 교체한다. 

	int max = 0;
	int left = 0;
	for (auto &i:input)
	{
		if (i > max)
		{
			left += max;
			max = i;
		}
		else
		{
			left += i;
		}
	}

	if (max >= left)
	{
		cout << left + left - 1;
	}
	else
	{
		cout << left + max;
	}



	return 0;
}