#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	// 입력 받은 문자열의 문자 하나를 입력 문자열에서 찾아본다.
	// 해당 인덱스를 반환하고 현재 찾고있는 문자와 비교해서 index값의 차이를 구한다.
	// 차이가 1이하이면 해당 값을 저장한 후,npos가 나올때까지 동일한 문자의 첫번째 인덱스를 찾는다.
	// 다시 인덱스를 비교하는 작업을 반복한다.
	// 만약 인덱스 값이 1을 넘으면
	// 해당 문자는 그룹단어가 아니므로 다음 단어를 가져와서 비교한다.

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

	for (int i = 0; i < input.size(); i++) //입력받은 문자열 개수만큼 체크
	{
		for (int j = 0; j < input[i].size(); j++) //문자열 속 단어의 개수만큼 체크
		{
			int index = input[i].find(input[i][j],j + 1); //문자열 안에서 단어 찾기
			//왜 인덱스 번호로 -1이 출력될까..
			//cout << index << endl;
			if (index == string::npos)
			{
				//아무 단어도 찾지 못했으므로 그룹 단어
			}
			else if (abs(index - j) <= 1)
			{
				//연속하였으므로 그룹 단어
			}
			else 
			{
				//단어를 찾았지만 연속하지 않으므로 그룹 단어 X
				countGroupWord--;
				break;
			}
		}
	}

	cout << N + countGroupWord;

	return 0;
}