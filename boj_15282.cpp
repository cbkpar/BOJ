#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecA(iN, 0);
	for(int i=0;i<iN;++i)
	{
		cin >> vecA[i];
	}

	vector<int> vecB(iM, 0);
	for(int i=0;i<iM;++i)
	{
		cin >> vecB[i];
	}

	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());

	int iNow = 0;
	int iAns = 0;
	for(int i=0;i<=iN;++i)
	{
		while(iNow < iM)
		{
			if(vecB[iNow] >= vecA[i])
			{
				++iNow;
				++iAns;
				break;
			}
			else
			{
				++iNow;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
