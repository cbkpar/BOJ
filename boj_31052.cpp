#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iQ;
	cin >> iN >> iQ;

	vector<int> vecNum(iN+1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNum[i];
	}

	while (iQ-- > 0)
	{
		int iCommand;
		cin >> iCommand;
		if (iCommand == 1)
		{
			int iC, iX;
			cin >> iC >> iX;
			vecNum[iC] = iX;
		}
		else if(iCommand == 2)
		{
			int iA, iB;
			cin >> iA >> iB;

			int iAns = abs(vecNum[iA] - vecNum[iB]);
			cout << iAns << "\n";
		}
	}

	return 0;
}
