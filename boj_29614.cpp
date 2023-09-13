#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double dSum = 0;
	double dCount = 0;

	string strScore;
	cin >> strScore;

	for (char ch : strScore)
	{
		if (ch >= 'A' && ch <= 'D')
		{
			dSum += 4.0 + 'A' - ch;
			dCount += 1.0;
		}
		if (ch == 'F')
		{
			dCount += 1.0;
		}
		if (ch == '+')
		{
			dSum += 0.5;
		}
	}

	cout.precision(30);
	cout << fixed;
	cout << (dSum / dCount) << "\n";
	return 0;
}
