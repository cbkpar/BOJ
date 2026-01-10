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

	int iInc = 0;
	int iDec = 0;
	for (int i = 1; i < iN; ++i)
	{
		if (vecNum[i] > vecNum[i - 1])
		{
			iDec += vecNum[i] - vecNum[i - 1];
		}
		else if (vecNum[i] < vecNum[i - 1])
		{
			iInc += vecNum[i - 1] - vecNum[i];
		}
	}

	cout << iInc << " " << iDec << "\n";
	return 0;
}
