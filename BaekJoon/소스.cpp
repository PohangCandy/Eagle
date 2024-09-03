#include <iostream>
#include <map>
using namespace std;

// ���ϸ��� �̸��� ��ȣ�� �����Ѵ�
// key�� �̸��� �ް� value�� ��ȣ�� �Է��Ѵ�.
// �ٵ� �̷��� value�� key���� ã�� �� �ֳ�?? 
// pair�� ���� Ű ���� �� ������ ����� ���?
// ���� ���ؼ���, �ܾ ���ؼ��� value���� �����غ���.

int main()
{
	ios_base::sync_with_stdio(false);
	map<string, int> dic;


	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		dic[input] = i + 1;
	}

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		//�̸��� �־��� ��� ��ȣ�� ����Ѵ�.
		if(dic.find(input) != dic.end())
			cout << dic[input] <<"\n";
		//��ȣ�� �־��� ��� �̸��� ��� ����ұ�?
		else {
			int size = input.size();
			int input_int = 0;
			for (auto& b : input)
			{
				int size_c = size;
				int i;
				i = (b - '0');
				while(size_c != 1)
				{
					i *= 10;
					size_c--;
				}
				input_int += i;
				size--;
			}
			for (auto& a : dic)
			{

			if (a.second == input_int)
			{
				cout << a.first << "\n";
			}
			}
		}
	}

	return 0;
}