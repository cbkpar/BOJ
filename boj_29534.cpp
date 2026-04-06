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
	cin >> iN;

	string strWord;
	cin >> strWord;

	int iLen = strWord.length();
	if (iLen > iN)
	{
		cout << "Impossible" << "\n";
	}
	else
	{
		int iCount = 0;
		for (char ch : strWord)
		{
			if (ch < 'a' || ch > 'z')
			{
				cout << "Impossible" << "\n";
				return 0;
			}
			iCount += (ch - 'a') + 1;
		}
		cout << iCount << "\n";
	}


	return 0;
}
