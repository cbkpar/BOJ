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

	string strWord;
	cin >> strWord;

	int iA = 0;
	int iB = 0;
	int iC = 0;
	int iD = 0;

	int iN = strWord.length();

	for (int i = 0;i < iN;++i)
	{
		if (strWord[i] == '0')
		{
			++iB;
			if (i == iN - 1)
			{
				if (strWord[0] == '1')
				{
					++iA;
				}
			}
			else
			{
				if (strWord[i + 1] == '1')
				{
					++iA;
				}
			}
		}
	}


	for (int i = 0;i < iN;++i)
	{
		if (strWord[i] == '1')
		{
			++iC;
		}
	}

	iD = iN;

	if (iA *iD == iC * iB)
	{
		cout << "EQUAL" << "\n";
	}
	else if(iA * iD > iC * iB)
	{
		cout << "ROTATE" << "\n";
	}
	else
	{
		cout << "SHOOT" << "\n";
	}
	return 0;
}
