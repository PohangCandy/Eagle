// �似Ǫ�� ����
// ��������� �ѷ� ���� ������� ��ȣ�� ���� �Ѹ� ���� ����
// 1 - 7 ���� ����
// 3 6 2(2) 7(5) 5(3) 1(1) 4
// �߰����� ��Ҹ� ���Ƿ� ����Ʈ�� �Ἥ �ۼ��ϰ�
// ���� �ݺ��ڰ� ����Ʈ�� ���� ��ġ�ϸ� �ٽ� begin���� ������.

#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	list<int> lst;

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		lst.push_back(i);
	}

	auto it = lst.begin();
	int last = 0;
	int q;
	while (!lst.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			if (it == lst.end())
			{
				it = lst.begin();
				it++;
			}
			else
			{
				it++;
			}
		}
		cout << *it << " ";
		it = lst.erase(it);
	}

	return 0;
}