#include <iostream>
#include <vector>
using namespace std;

// 100 * 100의 메모리 영역
// 사각형이 칠해지는 범위는 메모리에서 1로 표시됨
// 1로 표시된 범위를 모두 더하면 전체 넓이가 나온다
// 사각형의 넓이 10 *10이므로 x ~ x + 9
// 0 - 9, 0 - 9
// 0 - 99, 0 - 99

int paper[100][100] = {0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int x, y;
		cin >> x >> y;
		int range_x = x + 10;
		int range_y = y + 10;
		int before = y;
		for (x; x < range_x; x++)
		{
			y = before;
			for (y ; y < range_y; y++) 
			{
				paper[x][y] = 1;
			}
		}
	}

	int count = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (paper[i][j] == 1)
			{
				count++;
			}
		}
	}

	cout << count;


	return 0;
}