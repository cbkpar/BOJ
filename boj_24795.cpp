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

	vector<bool> vecNum(201, false);
	for (int i = 0; i < iK; ++i)
	{
		int iNum;
		cin >> iNum;
		vecNum[iNum] = true;
	}

	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (vecNum[i])
		{
			++iSum;
		}
		else
		{
			cout << i << "\n";
		}
	}
	cout << "Mario got " << iSum << " of the dangerous obstacles." << "\n";
	return 0;
}
