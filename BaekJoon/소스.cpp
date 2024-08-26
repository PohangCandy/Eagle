#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == b[i]) continue;
			// ���������� �� ū ģ���� �ڷ� �����Ѵ�.
			// �ƽ�Ű �ڵ��� ���� �� Ŭ���� ���������� �ڿ� ��ġ�ϴ� ���� �ȴ�.
			// �� ū ���� �ڷ� ������.
			else return b[i] > a[i];
		}
	}

	// ���̰� ��� �ڷ� �����Ѵ�.
	// length�� �� ū ���� �ڷ� �����ϹǷ�
	// a.length > b.length �� �ϸ� a�� �� Ŭ�� �տ� ��ġ�Ѵ�.
	// b.length > a.length ���ϸ� b�� �� Ŭ�� a�� �տ� ��ġ�Ѵ�. 
	return b.length() > a.length();
}

int main()
{
	ios_base::sync_with_stdio(false);
	vector<string> vec;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		vec.push_back(input);
	}

	// �ϴ� string �迭�� �־�д�.
	// sort �Լ��� ����° ���ڸ� ���ؼ� 
	// ���̷� ���ϰ�, ���ٸ� �ƽ�Ű �ڵ�� ���Ѵ�.
	// �ߺ��� �ܾ�� �����Ѵ�.

	sort(vec.begin(), vec.end(), compare);

	vec.erase(unique(vec.begin(), vec.end()),vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
		if (i != vec.size() - 1)
		{
			cout << "\n";
		}
	}

	return 0;
}