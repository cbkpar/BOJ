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

	int iN;
	cin >> iN;

	vector<string> vecWord(iN, "");
	for (int i = 0; i < iN; ++i) cin >> vecWord[i];

	string strGoal;
	cin >> strGoal;

	int iAns = 0;
	if (iN == 1)
	{
		if (vecWord[0] != strGoal)
		{
			iAns = 1;
		}
	}
	else
	{
		for (int i = 0; i < iN - 4; i += 2)
		{
			if (vecWord[i + 1] == "&")
			{
				if (vecWord[i] == "T" && vecWord[i + 2] == "T")
				{
					vecWord[i + 2] = "T";
				}
				else
				{
					vecWord[i + 2] = "F";
				}
			}
			else
			{
				if (vecWord[i] == "T" || vecWord[i + 2] == "T")
				{
					vecWord[i + 2] = "T";
				}
				else
				{
					vecWord[i + 2] = "F";
				}
			}
		}
		if (strGoal == "T")
		{
			if (vecWord[iN - 2] == "&")
			{
				if (vecWord[iN - 3] == "T" && vecWord[iN - 1] == "T")
				{
					iAns = 0;
				}
				else if (vecWord[iN - 3] == "T" || vecWord[iN - 1] == "T")
				{
					iAns = 1;
				}
				else
				{
					iAns = 2;
				}
			}
			else
			{
				if (vecWord[iN - 3] == "T" || vecWord[iN - 1] == "T")
				{
					iAns = 0;
				}
				else
				{
					iAns = 1;
				}
			}
		}
		else
		{
			if (vecWord[iN - 2] == "&")
			{
				if (vecWord[iN - 3] == "T" && vecWord[iN - 1] == "T")
				{
					iAns = 1;
				}
				else
				{
					iAns = 0;
				}
			}
			else
			{
				if (vecWord[iN - 3] == "T" && vecWord[iN - 1] == "T")
				{
					iAns = 2;
				}
				else if (vecWord[iN - 3] == "T" || vecWord[iN - 1] == "T")
				{
					iAns = 1;
				}
				else
				{
					iAns = 0;
				}
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
