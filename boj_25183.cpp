#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	string strWord;
	cin >> strWord;

	int iTemp = 1;
	int iLength = strWord.length();
	for (int i = 1; i < iLength; ++i)
	{
		int iDiff = strWord[i] - strWord[i - 1];
		if (iDiff == -1 || iDiff == 1)
		{
			++iTemp;
		}
		else
		{
			iTemp = 1;
		}
		if (iTemp == 5)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
