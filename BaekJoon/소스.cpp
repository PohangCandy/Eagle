// 골드바흐 파티션
// 짝수 N을 두 소수의 합으로 나타내는 표현
// 해당 수보다 작은 소수 집합을 벡터에 모아둔다.
// input - prime num을 한 결과의 인덱스 값이 0인지 확인한다.
// 0이라면 이미 계산된 값이거나 소수가 아니므로 continue한다.
// 0이 아니라면 count를 증가시키고 해당 값을 0으로 만들어준다.

#include <iostream>
#include <vector>
using namespace std;

//에라토스테네스
int eratostenas(int num)
{
	int count = 0;
	//0~n 까지 벡터를 만들어준다.
	vector<int> vec(num + 1, 0);

	for (int i = 2; i < vec.size(); i++)
	{
		vec[i] = i;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == 0) continue;
		else
		{
			for (int j = i * 2; j < vec.size(); j += i)
			{
				if (vec[j] == 0) continue;
				else  vec[j] = 0;
			}
		}

	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == 0) continue;
		else
		{
			if (vec[num - vec[i]] != 0)
			{
				count++;
				vec[i] = 0;
				vec[num - vec[i]] = 0;
			}
		}
	}

	
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	vector<int> result;
	
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		result.push_back(eratostenas(N));
	}

	for (auto& a : result)
	{
		cout << a << "\n";
	}

	return 0;
}