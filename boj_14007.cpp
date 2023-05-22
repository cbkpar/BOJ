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
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	int iCount = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iLen = 1;
		int iMode = 0;
		for (int j = i + 1; j < iN; ++j)
		{
			if (vecNum[j] > vecNum[j - 1])
			{
				if (iMode != 1)
				{
					++iLen;
					iMode = 1;
				}
				else
				{
					break;
				}
			}
			else if (vecNum[j] < vecNum[j - 1])
			{
				if (iMode != -1)
				{
					++iLen;
					iMode = -1;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		iCount += iLen;
	}
	cout << iCount << "\n";
	return 0;
}
