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

	string strCode;
	cin >> strCode;

	int iN;
	cin >> iN;
	while (iN-- > 0)
	{
		string strGuess;
		cin >> strGuess;

		int iA = 0;
		int iB = 0;
		vector<int> vecCountA(256, 0);
		vector<int> vecCountB(256, 0);

		int iLen = strCode.length();
		for (int i = 0;i < iLen;++i)
		{
			if (strCode[i] == strGuess[i])
			{
				++iA;
			}
			else
			{
				vecCountA[strCode[i]]++;
				vecCountB[strGuess[i]]++;
			}
		}
		for (int i = 0;i < 256;++i)
		{
			iB += min(vecCountA[i], vecCountB[i]);
		}
		cout << iA << " " << iB << "\n";
	}
	return 0;
}
