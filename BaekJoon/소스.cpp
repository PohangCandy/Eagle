#include <iostream>
#include <algorithm>
using namespace std;

int Tile[510][510] = { 0 };

int whenUptile(int i, int j)
{
	return Tile[i][j] + max({ Tile[i][j + 1],Tile[i][j - 1],Tile[i - 1][j] });
}
int whenDowntile(int i, int j)
{
	return Tile[i][j] + max({ Tile[i][j + 1],Tile[i][j - 1],Tile[i + 1][j] });
}
int whenLefttile(int i, int j)
{
	return Tile[i][j] + max({ Tile[i - 1][j],Tile[i + 1][j],Tile[i][j - 1] });
}
int whenRighttile(int i, int j)
{
	return Tile[i][j] + max({ Tile[i - 1][j],Tile[i + 1][j],Tile[i][j + 1] });
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 10; i < N + 10; i++)
	{
		for (int j = 10; j < M + 10; j++)
		{
			int input;
			cin >> input;
			Tile[i][j] = input;
		}
	}

	int total = 0;

	for (int i = 10; i < N + 10; i++)
	{

		for (int j = 10; j < M + 10; j++)
		{
			int up = Tile[i - 1][j] + max({ whenUptile(i - 2, j),whenRighttile(i - 1,j + 1),whenLefttile(i - 1,j - 1) });
			int down = Tile[i + 1][j] + max({ whenDowntile(i + 2, j),whenRighttile(i + 1,j + 1),whenLefttile(i + 1,j - 1) });
			int right = Tile[i][j + 1] + max({ whenRighttile(i, j + 2),whenUptile(i - 1,j + 1),whenDowntile(i + 1,j + 1) });
			int left = Tile[i][j - 1] + max({ whenLefttile(i, j - 2),whenUptile(i - 1,j - 1),whenDowntile(i + 1,j - 1) });

			int m = Tile[i][j] + max({ up,down,right,left });
			total = max(m, total);

			//한 개의 정사각형을 먼저 픽하는 경우
			up = Tile[i - 1][j] + max({ whenDowntile(i + 1, j),whenRighttile(i,j + 1),whenLefttile(i,j - 1) });
			down = Tile[i + 1][j] + max({ whenUptile(i - 1, j),whenRighttile(i,j + 1),whenLefttile(i,j - 1) });
			right = Tile[i][j + 1] + max({ whenLefttile(i,j - 1), whenUptile(i - 1, j),whenDowntile(i + 1, j) });
			left = Tile[i][j - 1] + max({ whenRighttile(i,j + 1), whenUptile(i - 1, j),whenDowntile(i + 1, j) });
			m = Tile[i][j] + max({ up,down,right,left });
			total = max(m, total);

			//두 개의 정사각형을 먼저 픽하는 경우
			up = Tile[i - 1][j];
			down = Tile[i + 1][j];
			right = Tile[i][j + 1];
			left = Tile[i][j - 1];
			m = Tile[i][j] + max({ up + down + right,up + down + left,up + right + left,down + right + left });
			total = max(m, total);
		}
	}

	cout << total;

	return 0;
}