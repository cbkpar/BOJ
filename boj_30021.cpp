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
	if (iN == 2)
	{
		cout << "NO" << "\n";
		return 0;
	}

	cout << "YES" << "\n";
	vector<int> vecAns;
	int iTemp = 0;
	for (int i = 1; i <= iN; i += 2)
	{
		if (((i + 1) / 2) % 2 == 1)
		{
			iTemp = i;
		}
		else
		{
			if (iTemp != 0)
			{
				vecAns.push_back(iTemp);
				iTemp = 0;
			}
			vecAns.push_back(i);
		}
	}
	for (int i = 2; i <= iN; i += 2)
	{
		vecAns.push_back(i);
	}
	if (iTemp != 0)
	{
		vecAns.push_back(iTemp);
		iTemp = 0;
	}

	for (int i = 0; i < iN; ++i)
	{
		cout << vecAns[i] << (i == iN - 1 ? "\n" : " ");
	}
	return 0;
}
