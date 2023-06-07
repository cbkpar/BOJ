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
	int iCount = iN;
	for (int i = 0; i < iN; ++i)
	{
		if (vecNum[i] == i)
		{
			--iCount;
		}
	}

	int iM;
	cin >> iM;
	for (int t = 1; t <= iM; ++t)
	{
		int iS, iE;
		cin >> iS >> iE;
		if (iS == vecNum[iS]) ++iCount;
		if (iE == vecNum[iE]) ++iCount;
		if (iS == vecNum[iE]) --iCount;
		if (iE == vecNum[iS]) --iCount;
		swap(vecNum[iS], vecNum[iE]);

		if (iN == 2)
		{
			cout << (iCount == 0 ? "0" : "1");
		}
		else
		{
			cout << (iCount == 0 ? "0" : "-1");
		}
		cout << (t == iM ? "\n" : " ");
	}
	return 0;
}
