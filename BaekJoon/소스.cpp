#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;

	vector<int> vec(M + 1, 0);

	//0,1은 소수가 아니므로 0으로 놔둔다.
	//크기가 M인 벡터에 2부터 인덱스와 일치한 수를 넣어둔 후, 
	for (int i = 2; i <= M; i++)
	{
		vec[i] = i;
	}

	//벡터 내부에서 이중 포문을 사용해서
	for (int i = 2; i * i <= M; i++)
	{
		//만약 자기자신의 값이 0이라면
		//이미 다른수의 배수라는 뜻이므로 건너뛴다.
		if (vec[i] == 0) continue;
		//아니라면 자기 자신을 제외한 배수들에 0을 대입한다.
		else
		{
			for (int j = i * 2; j <= M; j += i)
			{
				//공배수의 경우 이미 0이 되어 있을 수 있다.
				if (vec[j] == 0) continue;
				else vec[j] = 0;
			}
		}
	}

	//주어진 입력 범위에서 0이 아닌 값만 출력하면 된다.
	for (int i = N; i <= M; i++)
	{
		if (vec[i] != 0)
		{
			cout << vec[i] << " ";
		}
	}

	return 0;
}