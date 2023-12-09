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

	string strWord = "1";

	int iN;
	cin >> iN;

	if (iN >= 6)
	{
		cout << "3\n";
		return 0;
	}

	for (int i = 2; i <= iN; ++i)
	{
		char chTemp = ' ';
		int iCount = 0;
		string strNext = "";
		for (char ch : strWord)
		{
			if (ch != chTemp)
			{
				if (iCount != 0)
				{
					strNext = strNext + chTemp + to_string(iCount);
				}
				iCount = 1;
				chTemp = ch;
			}
			else
			{
				++iCount;
			}
		}
		strNext = strNext + chTemp + to_string(iCount);
		strWord = strNext;
	}

	char chAns = '1';
	for (char ch : strWord)
	{
		if (ch > chAns)
		{
			chAns = ch;
		}
	}
	
	cout << chAns << "\n";
	return 0;
}
