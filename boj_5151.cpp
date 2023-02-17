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
	for (int t = 1; t <= iT; ++t)
	{
		int iN, iM, iK;
		cin >> iN >> iM >> iK;
		vector<double> vecWeight(iN);
		while (iM--)
		{
			int iNum, iDay;
			double dWeight;
			cin >> iNum >> iDay >> dWeight;
			if (iK - iDay >= 0 && iK - iDay < 1000)
			{
				vecWeight[iNum - 1] += dWeight;
			}
		}
		double dYes = 0;
		double dNo = 0;
		for (int i = 0; i < iN; ++i)
		{
			string strVote;
			cin >> strVote;
			if (strVote[0] == 'N')
			{
				dNo += 1.0 / (1.0 + vecWeight[i] / 10000.0);
			}
			else
			{
				dYes += 1.0;
			}
		}
		cout << fixed;
		cout.precision(2);
		cout << "Data Set " << t << ":\n";
		cout << dYes << " " << dNo << "\n";
		if (t != iT) cout << "\n";
	}
	return 0;
}
