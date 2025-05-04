#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	if (iK == iN)
	{
		cout << "Impossible" << "\n";
		return 0;
	}

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		vecNum[i] = i;
	}

	int iRest = iN - 1 - iK;

	for (int i = 2; i <= iN; i += 2)
	{
		if (iRest < 2)
		{
			break;
		}
		iRest -= 2;
		swap(vecNum[i], vecNum[i + 1]);
	}

	if (iRest == 1)
	{
		swap(vecNum[1], vecNum[iN]);
	}

	for (int i = 1; i <= iN; ++i)
	{
		cout << vecNum[i] << (i == iN ? "\n" : " ");
	}
	return 0;
}
