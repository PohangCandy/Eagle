#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	// �Է� ���� ���ڿ��� ���� �ϳ��� �Է� ���ڿ����� ã�ƺ���.
	// �ش� �ε����� ��ȯ�ϰ� ���� ã���ִ� ���ڿ� ���ؼ� index���� ���̸� ���Ѵ�.
	// ���̰� 1�����̸� �ش� ���� ������ ��,npos�� ���ö����� ������ ������ ù��° �ε����� ã�´�.
	// �ٽ� �ε����� ���ϴ� �۾��� �ݺ��Ѵ�.
	// ���� �ε��� ���� 1�� ������
	// �ش� ���ڴ� �׷�ܾ �ƴϹǷ� ���� �ܾ �����ͼ� ���Ѵ�.

	vector<string> input;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		input.push_back(s);
	}

	int countGroupWord = 0;

	//for (int i = 0; i < input[0].size(); i++)
	//{
	//	int index = input[0].find(i ,"a");
	//	cout << index;
	//}

	for (int i = 0; i < input.size(); i++) //�Է¹��� ���ڿ� ������ŭ üũ
	{
		for (int j = 0; j < input[i].size(); j++) //���ڿ� �� �ܾ��� ������ŭ üũ
		{
			int index = input[i].find(input[i][j],j + 1); //���ڿ� �ȿ��� �ܾ� ã��
			//�� �ε��� ��ȣ�� -1�� ��µɱ�..
			//cout << index << endl;
			if (index == string::npos)
			{
				//�ƹ� �ܾ ã�� �������Ƿ� �׷� �ܾ�
			}
			else if (abs(index - j) <= 1)
			{
				//�����Ͽ����Ƿ� �׷� �ܾ�
			}
			else 
			{
				//�ܾ ã������ �������� �����Ƿ� �׷� �ܾ� X
				countGroupWord--;
				break;
			}
		}
	}

	cout << N + countGroupWord;

	return 0;
}