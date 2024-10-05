#include <iostream>
#include <vector>
using namespace std;
// 연속된 수 중에서 가장 합이 큰 최대 수열
// 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 
// 뒤에서부터 시작해서 합이 양수가 된다면
// 만약 input이 양수라면
// 더해주면 되지 않을까?

void RR(vector<pair<int, int>> &vec)
{
	for (int i = vec.size() - 1; i > 0; i--)
	{
		// 즉, 뒤에서 가져온 연속된 값의 최댓값이
		// 양수라면 앞의 연속되는 값에 그 값을 더한다.
		if(vec[i].second > 0)
		{
		  // 자신의 원값 + 뒤에 수에서 가져온 연속된 값의 최댓값
		  vec[i - 1].second = vec[i - 1].first + vec[i].second;
		}
	}
}

// pair<int 입력 값, int 현위치 연속의 최댓값>을 저장해준다.
vector<pair<int,int>> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		vec.push_back(make_pair(input, input));
	}

	RR(vec);

	//최댓값 초기화
	int max = 0;
	if (!vec.empty())
	{
		max = vec[0].second;
	}

	for (auto& a : vec)
	{
		if (a.second > max)
		{
			max = a.second;
		}
	}


	// 최종적으로 vector내의 가장 큰 값을 출력한다. 
	cout << max;

	return 0;
}