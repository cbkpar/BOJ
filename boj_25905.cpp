#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

float arrPercent[10] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double dPercent = 1;

	for (int i = 0; i < 10; ++i)
	{
		float fPercent;
		cin >> arrPercent[i];
	}
	sort(arrPercent, arrPercent + 10);
	for (int i = 1; i < 10; ++i)
	{
		dPercent *= arrPercent[i];
	}
	dPercent /= 0.00036288;
	cout.precision(30);
	cout << fixed << dPercent << "\n";
	return 0;
}
