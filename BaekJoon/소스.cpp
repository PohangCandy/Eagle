#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 자신보다 낮은 수가 몇 개 있는지 찾아본다.
	// 그냥 배열 안에서 자기 자신과 다른 수를 비교해가면 count를 늘리면 되는거 아닌가?
	// 배열 안에서 자신의 순위로 자기 자신을 바꾼다. 

	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> vec;
	vector<int> vec_copy;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
		vec_copy.push_back(input);
	}

	// 중복된 값의 경우 더 이상 count 치지 않는다.
	// 중복된 값을 제외하고 나열했을 때, 
	// 인덱스 번호가 해당 숫자보다 더 작은 값의 개수를 보여주게 된다.

	sort(vec_copy.begin(), vec_copy.end());
	vec_copy.erase(unique(vec_copy.begin(), vec_copy.end()), vec_copy.end());
	
	for (int i = 0; i < vec.size(); i++)
	{
		cout << lower_bound(vec_copy.begin(), vec_copy.end(), vec[i]) - vec_copy.begin() << " ";
	}
	return 0;
}