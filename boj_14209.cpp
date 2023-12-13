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
	vector<int> vecCount(26, 0);

	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;
		for (char ch : strWord)
		{
			++vecCount[ch - 'A'];
		}
	}

	int iSum = 0;
	iSum += vecCount['A' - 'A'] * 4;
	iSum += vecCount['K' - 'A'] * 3;
	iSum += vecCount['Q' - 'A'] * 2;
	iSum += vecCount['J' - 'A'] * 1;

	cout << iSum << "\n";
	return 0;
}
