//아이디어
// 같은 섬을 방문하지 않고, 다른 섬을 방문하는게 문제의 포인트 같다.
// 1. 섬 주변에 있는 타일을 찾는다.
// 2. 타일이 다른 섬에 닿을때까지 탐색한 높이를 저장한다.
// 3. 나온 높이의 최솟값을 출력한다.
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

//맵의 길이
int N;
// 맵 정보
int Tile[100][100] = {0};
// 땅이 속한 나라
// 0일 경우 강
int country[100][100] = {0};
// 탐색 방문 여부
int check[100][100] = { 0 };
// 다리의 길이 = 탐색 높이
int height[100][100] = {0};

//상하좌우
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

//탐색 첫번째, 두번째 섬 방문여부
bool from_i = false;
bool to_i = false;

//방문한 첫 번째, 두 번째 섬 인덱스 저장
int from;
int to;

//정답을 저장할 변수
//최대 방문 타일 100*100 가정
int ans = 10000;

//섬의 종류를 저장할 벡터 
vector<vector<pair<int, int>>> island;

void bfs_island(int y, int x, int c)
{
	//섬의 모든 좌표를 저장할 벡터
	vector<pair<int, int>> land;

	//bfs 탐색을 위한 큐
	queue<pair<int,int>> q;
	check[y][x] = 1;
	country[y][x] = c;
	q.push(make_pair(y, x));

	while (!q.empty())
	{
		int fy = q.front().first;
		int fx = q.front().second;
		land.push_back(q.front());
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			// 맵 범위를 벗어날 경우 continue
			if (fy + dy[i] < 0 || fy + dy[i] >= N || fx + dx[i] < 0 || fx + dx[i] >= N) continue;
			// 타일이 강인 경우 continue
			if (!Tile[fy + dy[i]][fx + dx[i]]) continue;
			// 이미 방문한 노드일 경우 continue
			if (check[fy + dy[i]][fx + dx[i]]) continue;
			//한번 방문한 땅은 방문 표시
			check[fy + dy[i]][fx + dx[i]] = 1;
			// 방문한 땅의 나라 표시
			country[fy + dy[i]][fx + dx[i]] = c;
			// 큐에 방문한 노드 push
			q.push(make_pair(fy + dy[i], fx + dx[i]));
		}
	}

	//섬에 지금까지 모아둔 좌표 담기
	island.push_back(land);
}

//강만 밟도록 만든 bfs
void bfs_ocean(int y, int x)
{
	//강에서 bfs를 하면서,
	//두번째로 방문할 섬을 찾자.
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	//첫 노드의 높이는 1
	height[y][x] = 1;

	while (!q.empty())
	{
		//다른 섬에 도착할때까지 방문을 한다.
		if (to_i) break;

		int fy = q.front().first;
		int fx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			//맵 범위를 벗어난 경우 continue
			if (fy + dy[i] < 0 || fy + dy[i] >= N || fx + dx[i] < 0 || fx + dx[i] >= N) continue;
			//이미 방문한 노드의 경우 continue
			if (check[fy + dy[i]][fx + dx[i]]) continue;
			//섬을 방문했을 경우
			if (Tile[fy + dy[i]][fx + dx[i]])
			{
				//출발한 섬을 방문했다면 continue
				if (country[fy + dy[i]][fx + dx[i]] == from) continue;
				//두 번째 섬에 도착한 경우
				//높이를 저장해둔다.
				ans = min(ans, height[fy][fx]);
				//두 번째 섬 방문 여부 표시
				to_i = true;
				//bfs에선 가장 먼저 도착했을 때가 최소 높이이므로
				//두번째 섬을 방문했다면 break한다.
				break;
			}
			//강을 방문했을 경우
			//방문 여부 표시
			check[fy + dy[i]][fx + dx[i]] = 1;
			//탐색 높이 표시
			height[fy + dy[i]][fx + dx[i]] = height[fy][fx] + 1;
			//새로 도착한 타일을 큐에 push
			q.push(make_pair(fy + dy[i], fx + dx[i]));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	//타일 맵 입력받기
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> Tile[y][x];
		}
	}

	//섬의 종류를 나눌 변수
	int c = 1;

	//섬 종류별로 나누기
	//각 땅이 어떤 섬에 속해있는지 담아준다.
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			//이미 방문한 땅은 가지 않는다.
			if (check[y][x]) continue;
			//강은 방문하지 않는다.
			if (!Tile[y][x]) continue;
			bfs_island(y, x, c);
			c++;
		}
	}

	////섬의 좌표를 한번 뽑아본다.
	//for (int i = 0; i < island[2].size(); i++)
	//{
	//	cout << island[2][i].first << "," << island[2][i].second;
	//	cout << "\n";
	//}

	//이제 바다에서 다리를 잇는다.
	//섬에 닿으면 이전에 섬과 닿은 적이 있는지 조사하고, 
	//닿은 적 없으면 연결한다.
	//닿인 적이 있다면 이전 섬과 지금 섬이 같은 섬인지 여부를 조사하고
	//이전과 같은 섬이라면 넘어가고
	// 다른섬이라면 그 섬까지의 거리를 잰다.
	// 
	// 섬 주변 노드에서 출발시키면 된다.
	// 상하좌우에 섬이 있는지 체크하고,
	// 섬이 없다면 넘어가고, 섬이 있다면
	// 첫번째 섬으로 저장한다.


	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			//탐색을 시작할 시작 지점을 정하는 작업을 한다.
			
			//주변에 섬이 있는 강만 조사한다.
			//주변에 있는 섬을 저장할 변수
			from_i = false;
			to_i = false;

			//새로 시작할 출발 노드를 갱신해주기 위해
			//방문 배열 초기화
			memset(check, 0, sizeof(check));
			//새로 탐색할 높이 갱신하기위한
			//높이 초기화
			memset(height, 0, sizeof(height));

			//방문한 적이 있는 노드는 패스
			if (check[y][x]) continue;
			//강이 아니라면 패스
			if (Tile[y][x]) continue;

			for (int i = 0; i < 4; i++)
			{
				if (from_i) break;
				if ((Tile[y + dy[i]][x + dx[i]]))
				{
					from_i = true;
					from = country[y + dy[i]][x + dx[i]];
				}
			}
			if (!from_i) continue;
			check[y][x] = 1;
			bfs_ocean(y, x);
		}
	}

	cout << ans;


	return 0;
}
