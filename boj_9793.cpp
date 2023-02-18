#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	cin.ignore();
	
	vector<int> arrCount(76);

	while (iT--)
	{
		string strCode;
		getline(cin, strCode);

		int iCount = 0;
		int iSize = strCode.length();
		bool bBlank = true;
		for (int i = 0; i < iSize; ++i)
		{
			if (strCode[i] == ' ')
			{
				bBlank = true;
			}
			else
			{
				if (bBlank)
				{
					bBlank = false;
					++iCount;
				}
			}
		}
		++arrCount[iCount];
	}
	for (int i = 2; i <= 75; ++i)
	{
		if (arrCount[i])
		{
			cout << i << " " << arrCount[i] << "\n";
		}
	}
	return 0;
}
