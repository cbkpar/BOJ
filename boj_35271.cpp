#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecCount(iM + 1, 0);
	for (int i = 1;i <= iM;++i)
	{
		cin >> vecCount[i];
	}

	for (int i = 0;i < iN;++i)
	{
		int iA, iB, iC;
		cin >> iA >> iB >> iC;

		int iAns = -1;
		if (vecCount[iA] > 0)
		{
			--vecCount[iA];
			iAns = iA;
		}
		else if (vecCount[iB] > 0)
		{
			--vecCount[iB];
			iAns = iB;
		}
		else if (vecCount[iC] > 0)
		{
			--vecCount[iC];
			iAns = iC;
		}

		cout << iAns << (i == iN - 1 ? "\n" : " ");
	}

	return 0;
}
