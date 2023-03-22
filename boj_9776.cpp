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

	int iT;
	cin >> iT;

	double dAns = 0;

	while (iT--)
	{
		string strShape;
		cin >> strShape;

		if (strShape == "C")
		{
			double dR, dH;
			cin >> dR >> dH;
			double dTemp = 3.14159 * dR * dR * dH / 3.0;
			dAns = max(dAns, dTemp);
		}
		else if (strShape == "L")
		{
			double dR, dH;
			cin >> dR >> dH;
			double dTemp = 3.14159 * dR * dR * dH;
			dAns = max(dAns, dTemp);
		}
		else
		{
			double dR;
			cin >> dR;
			double dTemp = 3.14159 * dR * dR * dR * 4.0 / 3.0;
			dAns = max(dAns, dTemp);
		}
	}
	printf("%.3lf\n", dAns);
	return 0;
}
