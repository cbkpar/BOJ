#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	string strD;
	cin >> iN >> strD;

	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < 4;++j)
		{
			string strCard;
			cin >> strCard;

			if (strCard[1] == strD[0])
			{
				if (strCard[0] == 'A') iAns += 11;
				if (strCard[0] == 'K') iAns += 4;
				if (strCard[0] == 'Q') iAns += 3;
				if (strCard[0] == 'J') iAns += 20;
				if (strCard[0] == 'T') iAns += 10;
				if (strCard[0] == '9') iAns += 14;
				if (strCard[0] == '8') iAns += 0;
				if (strCard[0] == '7') iAns += 0;
			}
			else
			{
				if (strCard[0] == 'A') iAns += 11;
				if (strCard[0] == 'K') iAns += 4;
				if (strCard[0] == 'Q') iAns += 3;
				if (strCard[0] == 'J') iAns += 2;
				if (strCard[0] == 'T') iAns += 10;
				if (strCard[0] == '9') iAns += 0;
				if (strCard[0] == '8') iAns += 0;
				if (strCard[0] == '7') iAns += 0;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
