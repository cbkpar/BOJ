#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	vector<int> vecCount(26, 0);

	string strWord;
	cin >> strWord;

	for (char ch : strWord)
	{
		++vecCount[ch - 'A'];
	}

	int iAns = iN;

	iAns = min(iAns, vecCount['B' - 'A']);
	iAns = min(iAns, vecCount['R' - 'A'] / 2);
	iAns = min(iAns, vecCount['O' - 'A']);
	iAns = min(iAns, vecCount['N' - 'A']);
	iAns = min(iAns, vecCount['Z' - 'A']);
	iAns = min(iAns, vecCount['E' - 'A'] / 2);
	iAns = min(iAns, vecCount['S' - 'A']);
	iAns = min(iAns, vecCount['I' - 'A']);
	iAns = min(iAns, vecCount['V' - 'A']);

	cout << iAns << "\n";
	return 0;
}
