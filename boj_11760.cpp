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

	string strA, strB;
	cin >> strA >> strB;

	vector<int> vecCount(26, 0);
	int iA, iB;
	iA = 0;
	iB = 0;

	for (int i = 0;i < iN;++i)
	{
		if (strA[i] == strB[i])
		{
			++iA;
		}
		else
		{
			vecCount[strA[i] - 'A']++;
		}
	}

	for (int i = 0;i < iN;++i)
	{
		if (strA[i] == strB[i])
		{
			continue;
		}
		else
		{
			if (vecCount[strB[i] - 'A'] > 0)
			{
				vecCount[strB[i] - 'A']--;
				++iB;
			}
		}
	}

	cout << iA << " " << iB << "\n";
	return 0;
}
