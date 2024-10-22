// 아이디어
//  루트 노드를 증가시키면서 방문하지 않은 노드를 방문하자.
//  DFS로 풀이하면 될 것 같다.
//  입력받은 N의 가지를 만들고
//  높이는 M이 된다.
// 
// 시간복잡도
//  각 가지는 N, 높이는 M이므로 
//  nPm의 순열이 된다.
// 
// 메모리
//  방문 여부를 저장할 int형 8배열
//  수를 저장할 int형 8배열
// 
// 자료형
//  8을 넘지 않으므로 int

int visited[8] = { 0 };

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	return 0;
}