#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<long long> vec;

	long long test;
	cin >> test;

	for (long long i = 0; i < test; i++)
	{
		long long input;
		cin >> input;
		long long copy = input;
		//0,1을 넣으면 2가 출력된다.
		if (copy < 2)
		{
			copy = 2;
			vec.push_back(copy);
		}
		else {
			while (1)
			{
				//벡터의 사이즈로 소수가 추가된 걸 확인
				long long size = vec.size();
				for (long long j = 2; j <= sqrt(copy); j++)
				{
					if (copy % j == 0)
					{
						break;
					}
					else if (j  + 1 > sqrt(copy))
					{
						vec.push_back(copy);
						break;
					}
				}
				if (size != vec.size())
				{
					break;
				}
				copy++;
			}
		}

	}

	for (auto& a : vec)
	{
		cout << a << "\n";
	}

	return 0;
}



