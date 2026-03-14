#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iA;
		cin >> iA;
		vector<int> vecA(iA, 0);
		for (int i = 0; i < iA; ++i)
		{
			cin >> vecA[i];
		}

		int iB;
		cin >> iB;
		vector<int> vecB(iB, 0);
		for (int i = 0; i < iB; ++i)
		{
			cin >> vecB[i];
		}

		sort(vecA.begin(), vecA.end());
		sort(vecB.begin(), vecB.end());

		int iAns = abs(vecA[0] - vecB[0]);

		int iNowA = 0;
		int iNowB = 0;
		while (iNowA < iA && iNowB < iB)
		{
			iAns = min(iAns, abs(vecA[iNowA] - vecB[iNowB]));
			if (vecA[iNowA] < vecB[iNowB])
			{
				++iNowA;
			}
			else
			{
				++iNowB;
			}
		}
		cout << iAns << "\n";
	}

	return 0;
}
