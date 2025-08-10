#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<int> vecNum;
	
	for (int i = 0; i < iN; ++i)
	{
		int iA, iB;
		cin >> iA >> iB;
		if (iB == 1)
		{
			vecNum.push_back(iA);
		}
	}

	int iAns = 0;
	int iSize = vecNum.size();
	for (int i = 1; i < iSize; ++i)
	{
		iAns = max(iAns, vecNum[i] - vecNum[i - 1]);
	}
	cout << iAns << "\n";
	return 0;
}
