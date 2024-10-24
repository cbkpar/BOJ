#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool IsPossible(string strWord)
{
	if (strWord.length() != 8) return false;

	if (strWord[0] != strWord[1]) return false;
	if (strWord[0] <= '0' || strWord[0] > '9') return false;

	if (strWord[2] <= '0' || strWord[2] > '9') return false;
	if (strWord[3] <= '0' || strWord[3] > '9') return false;

	if (strWord[4] < 'A' || strWord[4] > 'Z') return false;

	if (strWord[5] <= '0' || strWord[5] > '9') return false;
	if (strWord[6] <= '0' || strWord[6] > '9') return false;
	if (strWord[7] <= '0' || strWord[7] > '9') return false;

	return true;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;

		if (IsPossible(strWord))
		{
			cout << strWord << "\n";
		}
	}
	return 0;
}
