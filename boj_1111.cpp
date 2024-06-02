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

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}

	bool bSame = true;
	for (int i = 1; i < iN; ++i)
	{
		if (vecNum[i] != vecNum[i - 1])
		{
			bSame = false;
		}
	}

	if (bSame && iN >= 2)
	{
		cout << vecNum[0] << "\n";
		return 0;
	}

	if (iN <= 2)
	{
		cout << "A" << "\n";
		return 0;
	}

	if (vecNum[1] == vecNum[0])
	{
		cout << "B" << "\n";
		return 0;
	}

	if ((vecNum[2] - vecNum[1]) % (vecNum[1] - vecNum[0]) != 0)
	{
		cout << "B" << "\n";
		return 0;
	}

	int iA = (vecNum[2] - vecNum[1]) / (vecNum[1] - vecNum[0]);
	int iB = vecNum[1] - vecNum[0] * iA;

	bool bPossible = true;
	for (int i = 1; i < iN; ++i)
	{
		if (vecNum[i - 1] * iA + iB != vecNum[i])
		{
			bPossible = false;
		}
	}

	if (bPossible)
	{
		cout << (vecNum[iN - 1] * iA + iB) << "\n";
	}
	else
	{
		cout << "B" << "\n";
	}

	return 0;
}
