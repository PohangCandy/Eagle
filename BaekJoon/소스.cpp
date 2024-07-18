#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//cout << int('A');//65 - 55 = 10
	//cout << int('1');//49 - 48 = 1
	//�Է¹��� string N���� �� �ܾ �̰� 'A' �̻��� ��� -55�� �ؼ� ��Ÿ���� 10�������� ��ȯ�غ���.
	
	string input;
	int N;
	cin >> input >> N;

	int num = 0;
	for (int i = input.size(); i > 0; i--)
	{
		int squareNum = 1;
		if (input[i-1] >= 'A')
		{
			input[i-1] = input[i-1] - 'A' + 10;
		}
		else if (input[i - 1] >= '0')
		{
			input[i - 1] = input[i - 1] - '0';
		}
		for (int j = 0; j < input.size() - i; j++)
		{
			squareNum *= N;
		}
		num += int(input[i-1]) * squareNum;
	}

	cout << num;



	return 0;
}