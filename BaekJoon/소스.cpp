#include <iostream>
#include <sstream>
#include <vector>
// 공백문자를 건너뛰고 숫자를 저장하는 방법
// 
// 노가다 없이 최대공약수 구하기
// 유클리드 호제법 사용
#include <string>
using namespace std;


int GCD(int s, int b)
{
	if (b >= s)
	{
		if (b % s == 0)
		{
			return s;
		}
		else
		{
			return GCD(s, b % s);
		}
	}
	else
	{
		if (s % b == 0)
		{
			return b;
		}
		else
		{
			return GCD(b, s % b);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// 양의 정수 n개가 주어졌을때 가능한 모든 쌍의 GCD(Greatest Common Division) 합 구하기
	// 최대공약수 구하기
	// 2 4 2 4  10 10 10  10 20  10
	int t;
	cin >> t;

	vector<int> vec;
	vector<int> gcd;

	while (t > 0)
	{
		vec.clear();

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			vec.push_back(input);
		}
		//1, 000, 000 가 100개 주어질경우
		//100!이므로 longlong으로 만들어준다.
		//총 합의 범위는 10*99/2*1,000,000 이므로 49억이다??
		long long total = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = i + 1; j < vec.size(); j++)
			{
				total += GCD(vec[i], vec[j]);
			}
		}
		//3 125 15 25
		cout << total;
		if (t > 1)
		{
			cout << "\n";
		}
		t--;
	}
	


	return 0;
}