//아이디어
// 중복되는 수열을 여러 번 출력하면 안된다.
// 이전 수열에 대한 정보를 전부 저장하고 있으면 되려나??
// 
//시간복잡도
// N^M - > 최대 7^7
// 
//자료구조
// 메모리
//  벡터 int * 7
// 자료형
//  int형

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> vec;

int N, M;

//재귀함수가 stop할 조건
// 높이 M에 도달하면 stop
void RF(int s, int h)
{
	if (h == M)
	{
		for (auto& a : vec)
		{
			cout << a << " ";
		}
		cout << "\n";
	}
	else if (h > M)
	{
		cout << "out of height";
	}
	else
	{
		for (int i = s; i < N; i++)
		{
			vec.push_back(arr[i]);
			RF(i,h + 1);
			vec.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		vec.push_back(arr[i]);
		RF(i,1);
		vec.pop_back();
	}

	return 0;
}