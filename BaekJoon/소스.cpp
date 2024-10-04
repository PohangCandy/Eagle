#include <iostream>
#include <vector>
using namespace std;
//LIS�� ���Ҷ�, �ڽ��� ���������� ���Խ�Ű�� ������ ���� ������ ������ �־���Ѵ�.
// 10 20 10 30 20 50 �� ���
// 10	10
// 20	10,20 
// 10	10 
// 30	10,20,30
// 20	10,20
// 50	10,20,30,50

// 10 20 1 2 3 4 5 20
// 10	10
// 20	10,20
// 1	1
// 2	1,2
// 3	1,2,3
// 4	1,2,3,4
// 20	1,2,3,4
// �Էº��� ���� �� �� LIS�� ���� ū ģ���� ����
//  + push_back(�Է�)�� �����Ѵ�.
// 
// vector<int> �ڷ����� �����ϴ� 
// �迭�� ���� �����ϴ� ������ ��ƺ���.
// �׳� ������ ����ְ�, �ش� ������ ������� ���ص� �����ϴ�.


void RR(vector<int> arr[], int N)
{
	if (arr[N].size() == 0)
	{
		arr[N].push_back(N);
	}

	for (int i = 1; i <= (N - 1); i++)
	{
		if (arr[i].size() >= arr[N].size())
		{
			//LIS�� ������ �ʱ�ȭ��Ų��.
			arr[N].clear();
			arr[N] = arr[i];
			arr[N].push_back(N);
		}
	}
}

vector<int> test[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		RR(test, input);
	}

	int max = 0;
	int index = 1;
	for (int i = 1; i <= 1000; i++)
	{
		if (test[i].size() > max)
		{
			max = test[i].size();
			index = i;
		}
	}

	cout << test[index].size() << "\n";
	for (auto& a : test[index])
	{
		cout << a << " ";
	}


	return 0;
}