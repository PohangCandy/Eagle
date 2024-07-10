#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	float N;
	float Max;
	float sum = 0.0f;
	cin >> N;
	vector<float> vN(N);

	for (int i = 0; i < vN.size(); i++)
	{
		cin >> vN[i];
		Max = vN[i];
	}
	for (int i = 0; i < vN.size(); i++)
	{
		if (Max < vN[i])
		{
			Max = vN[i];
		}
	}
	for (int i = 0; i < vN.size(); i++)
	{
		
		vN[i] = vN[i] / Max * 100;
		sum += vN[i];
	}

	cout << fixed << setprecision(2);
	cout << sum / N;




	return 0;
}