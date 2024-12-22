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

	int iN, iM;
	cin >> iN >> iM;

	bool bPossible = true;
	
	for (int i = 0; i < iN; ++i)
	{
		int iCount = 0;
		for (int j = 0; j < iM; ++j)
		{
			string strCode;
			cin >> strCode;
			
			if (strCode == "A")
			{
				++iCount;
			}
		}
		if (iCount != 1) bPossible = false;
	}

	cout << (bPossible ? "Yes" : "No") << "\n";
	return 0;
}
