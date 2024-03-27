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

	int iOdd = 0;
	int iEven = 0;

	vector<int> vecCount(26, 0);
	for (char ch : strWord)
	{
		++vecCount[ch - 'a'];
	}

	int iAns = 0;
	for (int i = 0;i < 26;++i)
	{
		if (vecCount[i] == 0) continue;
		if (vecCount[i] % 2 == 0)
		{
			++iEven;
		}
		else
		{
			++iOdd;
		}
	}

	if (iEven > 0 && iOdd == 0)
	{
		cout << "0" << "\n";
	}
	else if (iOdd > 0 && iEven == 0)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << "2" << "\n";
	}
	return 0;
}
