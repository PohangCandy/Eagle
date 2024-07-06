#include <iostream>
using namespace std;

int main()
{
	int score;

	cin >> score;

	if (0 <= score && score < 60)
	{
		cout << "F";
	}
	else if (score <= 69)
	{
		cout << "D";
	}
	else if (score <= 79)
	{
		cout << "C";
	}
	else if (score <= 89)
	{
		cout << "B";
	}
	else if (score <= 100)
	{
		cout << "A";
	}


	return 0;
}

