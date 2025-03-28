#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iR;
	cin >> iN >> iR;

	int iCount = 0;
	vector<bool> vecVisited(iN + 1, false);
	for (int i = 0; i < iR; ++i)
	{
		int iNum;
		cin >> iNum;
		if (!vecVisited[iNum])
		{
			vecVisited[iNum] = true;
			++iCount;
		}
	}

	bool bSpace = false;
	if (iCount == iN)
	{
		cout << "*" << "\n";
	}
	else
	{
		for (int i = 1; i <= iN; ++i)
		{
			if (!vecVisited[i])
			{
				if (bSpace) cout << " ";
				cout << i;
				bSpace = true;
			}
		}
		cout << "\n";
	}


	return 0;
}
