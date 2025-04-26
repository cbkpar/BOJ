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

	int iW, iH;
	cin >> iW >> iH;

	int iN, iD;
	cin >> iN >> iD;

	vector<int> vecA(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecA[i];
	}

	vector<int> vecP(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecP[i];
	}

	int iAns = 0;
	for (int i = 1; i <= iN; ++i)
	{
		if (vecA[i - 1] < iD && iD >= vecA[i])
		{
			iAns += (iD - vecA[i]) * vecP[i];
			iAns += iW * vecP[i];
			break;
		}
		else
		{
			iAns += (vecA[i] - vecA[i - 1]) * vecP[i];
		}
	}


	cout << iAns << "\n";
	return 0;
}
