//�������� ��ġ�� ǳ���� ���� ������� ��Ʈ����

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	deque<int> deq;
	vector<int> paper;
	vector<int> result;

	int N;
	cin >> N;
	// ���� �̿��ؼ� �����ִ� ǳ���� ��ȣ�� ǥ���Ѵ�.
	// 2 ~ N���� ����Ǿ��ִ� ���� �����.
	for (int i = 2; i <= N; i++)
	{
		deq.push_back(i);
	}
	//�׻� ù ��° ǳ���� ���� ������.
	result.push_back(1);

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		paper.push_back(input);
	}

	// �Է��� �޴� Ƚ��
	// ǳ���� ��Ʈ���� Ƚ���� �� n���̴�.
	// �Է� ������� ���� �ʴ´�.
	// �Է��� ���� �� ǳ���� �����ִ� ���� ǳ�� ���� ��ȣ�̴�.
	int index = 1;
	while (1)
	{
		if (deq.empty()) break;
		//vec�� 0���� �����ϹǷ� -1���ش�.
		int next = paper[index-1];

		if (next > 0)
		{
			// input = 3
			// 2 3 4 5
			// 5 2 3 "4"
			while (next != 0)
			{
				deq.push_back(deq.front());
				deq.pop_front();
				//cout << "move front_deq " << deq.back() << "to back" << "\n";
				next--;
			}
			result.push_back(deq.back());
			//cout << "push back_deq " << deq.back() << "to vec" << "\n";
			index = deq.back();
			deq.pop_back();
		}
		else if (next < 0)
		{
			// input = -3
			// 2 3 4 5
			// "3" 4 5 2
			while (next != 0)
			{
				deq.push_front(deq.back());
				deq.pop_back();
				//cout << "move back_deq " << deq.front() << "to front" << "\n";
				next++;
			}
			result.push_back(deq.front());
			//cout << "push front_deq " << deq.front() << "to vec" << "\n";
			index = deq.front();
			deq.pop_front();
		}
	}

	for (auto& a : result)
	{
		cout << a << " ";
	}

	return 0;
}