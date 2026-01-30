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

	string strA, strB;
	cin >> strA >> strB;

	vector<int> vecCount(26, 0);
	for (char ch : strA)
	{
		vecCount[ch - 'a']++;
	}

	int iStar = 0;
	for (char ch : strB)
	{
		if (ch == '*')
		{
			++iStar;
		}
		else
		{
			--vecCount[ch - 'a'];
		}
	}

	bool bPossible = true;
	for (int i = 0;i < 26;++i)
	{
		if (vecCount[i] < 0)
		{
			bPossible = false;
		}
		else
		{
			iStar -= vecCount[i];
		}
	}
	if (iStar < 0) bPossible = false;

	cout << (bPossible ? "A" : "N") << "\n";
	return 0;
}
