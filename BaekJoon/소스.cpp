#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// �ڽź��� ���� ���� �� �� �ִ��� ã�ƺ���.
	// �׳� �迭 �ȿ��� �ڱ� �ڽŰ� �ٸ� ���� ���ذ��� count�� �ø��� �Ǵ°� �ƴѰ�?
	// �迭 �ȿ��� �ڽ��� ������ �ڱ� �ڽ��� �ٲ۴�. 

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

	// �ߺ��� ���� ��� �� �̻� count ġ�� �ʴ´�.
	// �ߺ��� ���� �����ϰ� �������� ��, 
	// �ε��� ��ȣ�� �ش� ���ں��� �� ���� ���� ������ �����ְ� �ȴ�.

	sort(vec_copy.begin(), vec_copy.end());
	vec_copy.erase(unique(vec_copy.begin(), vec_copy.end()), vec_copy.end());
	
	for (int i = 0; i < vec.size(); i++)
	{
		cout << lower_bound(vec_copy.begin(), vec_copy.end(), vec[i]) - vec_copy.begin() << " ";
	}
	return 0;
}