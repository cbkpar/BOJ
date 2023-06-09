#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iMonth1, iYear1;
		cin >> iMonth1 >> iYear1;

		int iMonth2, iYear2;
		cin >> iMonth2 >> iYear2;

		double dAns = 0.0;

		if (iYear1 == iYear2)
		{
			dAns += 0.5 * ((double)iMonth2 - iMonth1) * (1.0 / (13.0 - iMonth1));
		}
		else
		{
			dAns += 0.5;
			++iYear1;
			dAns += (double)iYear2 - iYear1;
			dAns += ((double)iMonth2 - 1) / 12.0;
		}
		printf("%.04f\n", dAns);
	}
	return 0;
}
