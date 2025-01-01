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

	int iLen = strWord.length();

	bool bPossible = true;
	if (iLen % 2 != 1 || iLen <= 2 || strWord[iLen / 2] != '+')
	{
		cout << "No Money" << "\n";
		return 0;
	}

	if (strWord[0] <= '0' || strWord[0] > '9')
	{
		cout << "No Money" << "\n";
		return 0;
	}

	int iLenHalf = iLen / 2;
	for (int i = 0;i < iLenHalf;++i)
	{
		if (strWord[i] != strWord[iLenHalf + i + 1])
		{

			cout << "No Money" << "\n";
			return 0;
		}
	}
	cout << "CUTE" << "\n";


	return 0;
}
