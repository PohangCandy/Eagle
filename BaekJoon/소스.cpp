#include <iostream>
using namespace std;

int N, M;

//입력 값을 저장할 배열
int rectangle[500][500];
//방문한 노드에 대해 체크할 배열을 전역 변수 선언한다.
int visited[500][500] = { 0 };

//상하좌우
//xpos + dx
int dx[4] = { 0,0,-1,1 };
//ypos + dy
int dy[4] = { -1,1,0,0 };

//정답을 저장할 전역변수
int result = 0;

// dfs가 멈출 조건을 정한다.
// 4번째 사각형일때 멈춰야한다.
// 어떤 파라미터를 받을까?
// 기준이 되는 사각형의 위치 x,y를 받아야 한다.
// 현재 사각형이 몇 번째인지 셀 변수cnt가 필요하다.
// 4번째 사각형에 도착하면, 
// 4번째 사각형을 포함하는 값을 더한 값과 
// 지금까지의 최댓 값을 비교한 후
// 더 큰 값을 저장해야한다.
// 지금까지 사각형의 합을 저장하고 있는 변수를 넘겨준다.
void dfs(int y, int x, int cnt, int sum)
{
	// 먼저 지금이 4번째 사각형인지 체크한다.
	// 4번째 사각형을 포함하는 값을 더한 값과 
	// 지금까지의 최댓 값을 비교한 후
	// 더 큰 값을 저장해야한다.
	if (cnt == 4)
	{
		result = max(result, sum);
	}
	//기준점으로부터 상하좌우 방향으로 dfs를 구한다.
	//이미 방문한 노드는 방문하지 않게 해준다.
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			//범위를 벗어나지 않도록 해준다.
			if (nx < 0 || ny < 0 || nx > M || ny > N) continue;

			//한번 방문한 노드는 재방문 하지 않는다.
			if (visited[ny][nx] == 1) continue;

			//방문한 노드로 표시
			visited[ny][nx] = 1;
			dfs(ny, nx, cnt + 1, sum + rectangle[ny][nx]);

			//방문한 노드 초기화
			visited[ny][nx] = 0;
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//전체 판 배치하기
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int input;
			cin >> input;
			rectangle[i][j] = input;
		}
	}

	// 한 칸씩 bfs를 통해 4개의 사각형을 만들어준다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//방문한 노드로 표시
			visited[i][j] = 1;
			dfs(i , j , 1, rectangle[i][j]);
			//검색이 끝난후엔 다시 초기화
			visited[i][j] = 0;
		}
	}

	//ㅏ,ㅗ,ㅓ,ㅜ,와 같은 부분을 고려해준다.
	//기준점을 중심으로 상하좌우 중 가장 최솟값을 제외하고 모두 더한다.

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 상,하,좌,우 중에서 가장 작은 값 1개를 제외하고
			// 3가지를 고르는 경우
			int m = 501;
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				//범위 밖의 값은 0으로 받아준다.
				if ((i + dy[k]) < 0 || (j + dx[k]) < 0)
				{
					m = 0;
					sum += 0;
					continue;
				}

				sum += rectangle[i + dy[k]][j + dx[k]];
				m = min(m,rectangle[i + dy[k]][j + dx[k]]);
			}

			result = max(result, rectangle[i][j]+ sum - m);
		}
	}

	cout << result;

	return 0;
}
