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

	string strWord;
	cin >> strWord;

	bool bFound = false;
	for (int i = 3; i < iN; ++i)
	{
		if (strWord[i - 3] == 'g' && strWord[i - 2] == 'o' && strWord[i - 1] == 'r' && strWord[i] == 'i')
		{
			bFound = true;
		}
	}

	if (bFound)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}
