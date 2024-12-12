//아이디어
// 노드 클래스를 만들고, 루트, 자식에 정보를 담는다.
// 모든 노드를 컨테이너에 담아두었다가,
// 전위, 중위, 후위 순서에 따라 노드를 방문할때
// 알파벳의 인덱스에 해당하는 번호로 이동하게 해준다.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
	char root;
	char leftChild;
	char rightChild;

public:
	Node(char _root, char _lc = '.', char _rc = '.') : root(_root), leftChild(_lc), rightChild(_rc) {}

	char getLc()
	{
		return leftChild;
	}

	char getRc()
	{
		return rightChild;
	}

	char getRoot()
	{
		return root;
	}
};

//모든 노드를 저장할 컨테이너
vector<Node> Tree[26];


//전위는 스택을 사용하면 된다.
// rc,lc순으로 넣는다.
//A
//C,B
//C,D
//F,E
//G
void pT()
{
	stack<Node> s;
	//처음 A 삽입
	s.push(Tree[0][0]);

	while(!s.empty())
	{
		Node n = s.top();
		cout << n.getRoot();
		s.pop();

		//반횐되는 문자열을 인덱스로 변환
		//왼쪽을 먼저 탐색하기위해 나중에 삽입(LILO)
		if (n.getRc() != '.')
		{
			Node rc = Tree[n.getRc() - 'A'][0];
			s.push(rc);
		}
		if (n.getLc() != '.')
		{
			Node lc = Tree[n.getLc() - 'A'][0];
			s.push(lc);
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char r, lc, rc;
		cin >> r >> lc >> rc;
		Node n(r, lc, rc);

		Tree[r - 'A'].push_back(n);
	}

	pT();
	//mT();
	//bT();

	return 0;
}
