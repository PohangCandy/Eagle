#include <iostream>
using namespace std;

//아이디어
// 최대 랜선의 길이는 2^31 - 1 , 약 2 * 10^9
// 최대 길이 ~ 1까지 모두 조사하면 시초가 난다.
// N개를 만들 수 있는 랜선의 길이를 어떻게 줄일 수 있을까..
// 모든 랜선의 길이를 다 더한후 K로 나눈 값부터 조사하면 어떨까
// 1. 주어진 랜선을 모두 더한다.(최대 10^4개)
// 2. 랜선을 필요한 랜선의 개수로 나눈다.(1 ~ 10^6개)
// 3. 최대 길이(2 * 10^9)
// ex) 2 * 10^9길이의 랜선 10^4개를 모두 더하면
//  -> 2 * 10^9 * 10^4 = 2 * 10^13이므로 longlong에 담아준다.
// 
// 만약 10^4개의 랜선이 10^6길이를 가지고 있고 
// 필요한 랜선의 개수가 1인 경우
// 10^4 * 10^6 / 1 = 10^10이므로 
// 최대 10초의 시간복잡도를 가지게된다.
//
// 정답이 될 랜선의 길이를 x라고 가정한다.
// 첫 번째 랜선과 x를 나눈 몫을 구한다.
// 나눈 몫의 개수가 필요한 랜선의 개수인지 확인해본다.
// 필요한 랜서의 길이는 최대 길이를 구하므로
// 랜선이 1개 필요하다면, K개의 랜선 중에 가장 긴 값이 정답이 된다.
// 최대 길이에서 k개의 랜선이 나올 수 있는 경우는 어떨까?
// 802 , 743에서 
// 1개의 랜선이 필요한 경우, 랜선의 길이는 802 
// 2개의 랜선이 필요한 경우, 랜선의 길이는 743
// 3개의 랜선이 필요한 경우, 랜선의 길이는 802/2 = 401
// 4개의 랜선이 필요한 경우, 802/3 or 743/2
// 최대 길이에서 랜선 1~k개를 뽑는 경우의 수를 저장해둔다.
// 최대 길이에서 랜선 x개를 뽑았다면
// 두번째 길이에선 랜선 0 ~ k-x개를 뽑는다.
// 뽑은 개수가 K개를 충족하면 그만 뽑는다.
// 1개를 뽑을 경우는 1~802까지 모두 가능하다는 얘긴데
//
// 최솟값부터 최댓값까지 정렬해준다.
// 최솟값을 0~K개까지 선택하는 경우의 수를 구한다.
// 457은 0~457개 까지 선택할 수 있다.
// n이 아무라 커도 최대 10000개까지만 선택할 수 있다.
// 10^6개의 수를 10^4개까지 선택하는 경우의 수를 고려하면,
// 10^6 * 10^4 = 10^10 -> 시초
// 
// 최대 길이라서 dp로 풀어야 될 것 처럼 보이는데
// 1 1 100인 경우 필요한 랜선이 2개라면 최대 길이는 1이 된다.

//이번에 넥토리얼에서 푼 초콜릿 문제가 떠올랐다.
//주어진 랜선보다 더 많은 개수의 랜선이 필요한 경우, 
//3개가 필요한 경우, 
//가장 긴 길이의 랜선 이등분 401
//4개 필요한 경우,
// 가장 긴 길이를 3등분하거나, 267 
// 두번째로 긴 길이 2등분 371
//5개 필요하다면
// 5,0 1,4 2,3 3,2 4,1 0,5
// 160,0  200,743  267,371  401,247  802,185  0,148


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K, N;
	cin >> K >> N;

	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		sum += input;
	}

	//나올 수 있는 최대의 길이
	long long maxi = sum / N;

	return 0;
}
