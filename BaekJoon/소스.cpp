#include <iostream>
#include <algorithm>
using namespace std;

//�ִ���

/*
�� �� �ٲ㼭, ���� �� ������ �ִ� �� ����ϱ�
������ �迭�� ���� �ڿ�, �ڿ� �ְų� �Ʒ��� �ִ� ���, count�� ������Ų��.
max�� �Ǵ� count ���� �����Ų��.

���� ������ �ִ�� ���� �� �ִ� �迭�� �����.
�Է��� �Է� ����ŭ, ���� �迭�� ���� �迭�� ���� ������Ų��.

���� 4���� ���� �迭�� ���� �����.

i,j��° ��ҿ���
���ο� ���� ���� ��� ������� ������?
���η� ������Ű�鼭 �ִ� ��� ���ӵ� �� �ִ���
�����ϰ�
���η� ������Ű�鼭 �ִ� ��� �� �� �ִ���
�����غ���.

80%���� �����.
�ݷʰ� �߻��ϰ� �ֱ⶧����
���ܰ� �ִ��� ��� ������ ����غ���.

�������� ��찡 �ִ�.

p p p c p p p p
z y z z y z y z
���� ���� ��� 
p p p���Ŀ� ���� c,p�� ��ȯ�ϴ� ���
p p p (p c) p p p �� ��ü�ϸ� �� ���� p�� 4��, �� ���� 3���� �ȴ�.
p p (c p) p p p p �� ��ü�ϸ� �� ���� p�� 3��, �� ���� 5���� �ȴ�.

���θ� �˻��Ҷ�
for(int i  = 0 ; i < N; i++)
for(int j = 0 ; i < N ; j++)
for(int k = j+1; k < N; k++)
[i][j]��° ��ҿ� [i][k]��° ��Ҹ� ��������

[i][j] == [i][k]���, ���ӵ� ���� �����ϴ� �迭�� ����ش�.
arr[0] ++;
arr[1]++, ü������ �ѹ� ������ ����� �򿭵� �Ȱ��� �����Ѵ�.

[i][j] != [i][k]����,
�ڸ� ü������ ���� ���ӵ� �� �ִ��� ���� �˾ƺ���.

1. ��,�� ü������ ���ӵǴ� ��� 
[i][j] == [i+1][k] || [i][j] == [i-1][k]
arr[1] = arr[0] + 1; ���ݱ��� ���ӵ� �� + ü������ ���� ������ 1
���ӵ� ���� �����ϴ� �迭�� �ʱ�ȭ
arr[0] = 0 ;

2. ��, �� ü������ ���ӵǴ� ���
[i][j] == [i][k+1] == [i][k-1]�� ���
k = 1�϶�
P C P ���� ��츦 ���Ѵ�.

*/

char anipang[51][51];

//�̹� �� �� �ٲ��� ����, �� ���� �� �ٲ��� ��츦 ������ش�.
int arr[2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			char c;
			cin >> c;
			anipang[i][j] = c;
		}
	}

	int M = 1;

	//���ο� ���ؼ� ���� ����

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[0] = 1;
			arr[1] = 1;
			char basicWord = anipang[i][j];
			for (int k = j + 1; k <= N; k++)
			{
				if (basicWord == anipang[i][k])
				{
					arr[0]++;
					arr[1]++; 
				}
				else if (basicWord == anipang[i + 1][k] || basicWord == anipang[i - 1][k])
				{
					arr[1] = arr[0] + 1;
					arr[0] = 0;
				}
				else if (k + 1 < N && basicWord == anipang[i][k+2] && anipang[i][k-1] == anipang[i][k + 1])
				{
					arr[1] = arr[0] + 1;
					M = max({ M,arr[0], arr[1]});
					arr[1] = 1;
					arr[0] = 0;
				}
				else
				{
					//p p p c p p p p
					//c c p c c p
					arr[1] = 0;
					arr[0] = 0;
				}
				M = max({M,arr[0], arr[1]});
			}
		}
	}

	//���ο� ���� ����
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[0] = 1;
			arr[1] = 1;
			char basicWord = anipang[j][i];
			for (int k = j + 1; k <= N; k++)
			{
				if (basicWord == anipang[k][i])
				{
					arr[0]++;
					arr[1]++;
				}
				else if (basicWord == anipang[k][i+1] || basicWord == anipang[k][i-1])
				{
					arr[1] = arr[0] + 1;
					arr[0] = 0;
				}
				else if (k + 1 < N && basicWord == anipang[k + 1][i])
				{
					arr[1] = arr[0] + 1;
					M = max({ M,arr[0], arr[1] });
					arr[1] = 1;
					arr[0] = 0;
				}
				else
				{
					arr[1] = 0;
					arr[0] = 0;
				}

				M = max({ M,arr[0], arr[1] });
			}
		}
	}

	cout << M;


	return 0;
}