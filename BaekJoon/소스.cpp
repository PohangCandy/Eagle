//에라토스테네스의 체가 여기서도 활용된다.
//소수 관련 문제면 다 활용되는 듯
#include <iostream>
#include <algorithm>
using namespace std;

void IsPrimeNum(bool arr[], int size)
{
	//0과 1은 소수가 아니다.
	arr[0] = false;
	arr[1] = false;
	/*25가 소수인지 판단하기 위해서 5까지만 조사하면 되듯이
	25보다 작은 수는 제곱수라고 해도 약수로 5보다 작은 값을 가질 것이다.
	그러므로 25보다 적은 수 중 5보다 작은 수의 배수가 아니라면 소수가 된다.*/
	
	// 그러므로 모든 size보다 작은 소수를 찾는 작업은
	// size의 제곱근까지만 조사하면 된다.
	// 배수들을 false로 만들어준다.
	for (int i = 0; i * i < size; i++)
	{
		//이미 다른 수의 배수라면 넘어간다.
		if (arr[i] == false) continue;
		else
		{
			// i의 배수들을 찾아준다.
			// i * 2 , i * 3은 이미 2,3의 배수로 처리되었기 때문에
			//i * i부터 찾아주자.
			for (int j = i * i; j < size; j += i)
			{
				arr[j] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool *che = new bool[1000001];
	//메모리 안의 모든 수를 소수로 초기화
	fill(che, che + 1000001, true);
	IsPrimeNum(che, 1000001);
	bool find;
	int MaxTextSize = 1000000;
	while (MaxTextSize > 0)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		find = false;
		//인덱스 값이 소수일때 true인 배열에서
		//합이 n인 짝을 찾는다.
		//인덱스 번호는 n/2까지만 찾으면된다.
		//홀수인 소수 조합을 찾으므로
		//홀수인 인덱스 번호만 조사한다.

		for (int i = 3; i <= n / 2; i += 2)
		{
			// 두 수가 소수이면 break하고 출력한다.
			if (che[i] && che[n - i])
			{
				find = true;
				cout << n << " = " << i << " + " << n - i << "\n";
				break;
			}
		}

		if (!find)
		{
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
		
		MaxTextSize--;
	}

	delete[] che;
	return 0;
}