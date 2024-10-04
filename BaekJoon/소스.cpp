#include <iostream>
#include <vector>
using namespace std;
//LIS를 구할때, 자신이 마지막으로 포함시키는 수열에 대한 정보를 가지고 있어야한다.
// 10 20 10 30 20 50 일 경우
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
// 입력보다 작은 수 중 LIS가 가장 큰 친구의 수열
//  + push_back(입력)을 저장한다.
// 
// vector<int> 자료형을 저장하는 
// 배열를 만들어서 저장하는 공간에 담아본다.
// 그냥 수열만 담아주고, 해당 수열의 사이즈로 비교해도 가능하다.


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
			//LIS의 수열을 초기화시킨다.
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