#include<iostream>

#define endl "\n"
using namespace std;

int dp[100001][2], arr[100001];
int N;

void Answer()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dp[0][0] = arr[0];
	dp[0][1] = arr[0];
	// ���� �ִ밪�� �� �� �ִ� ���� ��´�.
	int MAX = arr[0];
	for (int i = 1; i < N; i++)
	{
		// ������ �������� �ʾ�����
		// ��������� ������ �Էº��� �۴ٸ�
		// �� , arr[i] > dp[i - 1][0] + arr[i]�̶��
		// �� ��� dp[i - 1][0] > 0�̶�� �ǹ��̴�.
		// dp[i - 1][0]�� ���ó���ϰ� arr[i]�� dp[i]�� ��´�.
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		//������ ������ ���
		//���� �Է����� ���� ������ ������ ���
		//dp[i - 1][0]�� dp[i][1]�� �������ְ�,
		//������ ������ �̹� ������ ���հ� ������ �Է��� ���ϴ� ���
		//dp[i-1][1] + arr[i]�� �������ش�.
		//��, ���� �Է��� �����ϴ� ���� ������ �Է��� ������ ��츦 ���ؼ�
		//�� ���� ������ ���ŵǰ� ���ش�.
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);

		MAX = max(MAX, max(dp[i][0], dp[i][1]));
	}
	cout << MAX;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Answer();
	return 0;
}