#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iA, iB;
	cin >> iN >> iA >> iB;

	vector<bool> vecNum(iB + 1, false);
	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;
		vecNum[iNum] = true;
	}

	if (iA == iB)
	{
		cout << iA << "\n";
	}
	else if (!vecNum[iA] && !vecNum[iB])
	{
		cout << "-1" << "\n";
	}
	else if (vecNum[iA] && !vecNum[iB])
	{
		cout << iB << "\n";
	}
	else if (!vecNum[iA] && vecNum[iB])
	{
		cout << iA << "\n";
	}
	else
	{
		for (int i = iA;i <= iB;++i)
		{
			cout << i << (i == iB ? "\n" : " ");
		}
	}

	return 0;
}
