#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;

	vector<int> vec(M + 1, 0);

	//0,1�� �Ҽ��� �ƴϹǷ� 0���� ���д�.
	//ũ�Ⱑ M�� ���Ϳ� 2���� �ε����� ��ġ�� ���� �־�� ��, 
	for (int i = 2; i <= M; i++)
	{
		vec[i] = i;
	}

	//���� ���ο��� ���� ������ ����ؼ�
	for (int i = 2; i * i <= M; i++)
	{
		//���� �ڱ��ڽ��� ���� 0�̶��
		//�̹� �ٸ����� ������ ���̹Ƿ� �ǳʶڴ�.
		if (vec[i] == 0) continue;
		//�ƴ϶�� �ڱ� �ڽ��� ������ ����鿡 0�� �����Ѵ�.
		else
		{
			for (int j = i * 2; j <= M; j += i)
			{
				//������� ��� �̹� 0�� �Ǿ� ���� �� �ִ�.
				if (vec[j] == 0) continue;
				else vec[j] = 0;
			}
		}
	}

	//�־��� �Է� �������� 0�� �ƴ� ���� ����ϸ� �ȴ�.
	for (int i = N; i <= M; i++)
	{
		if (vec[i] != 0)
		{
			cout << vec[i] << " ";
		}
	}

	return 0;
}