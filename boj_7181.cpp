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

	string strPW;
	cin >> strPW;

	vector<int> vecCount(10, 0);
	vecCount[strPW[0] - '0']++;
	vecCount[strPW[1] - '0']++;
	vecCount[strPW[2] - '0']++;
	vecCount[strPW[3] - '0']++;

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		string strGuess;
		cin >> strGuess;

		vector<int> vecCount2(10, 0);
		vecCount2[strGuess[0] - '0']++;
		vecCount2[strGuess[1] - '0']++;
		vecCount2[strGuess[2] - '0']++;
		vecCount2[strGuess[3] - '0']++;
		
		int iAnsA = 0;
		int iAnsB = 0;
		for (int i = 0; i < 10; ++i)
		{
			iAnsA += min(vecCount[i], vecCount2[i]);
		}
		for (int i = 0; i < 4; ++i)
		{
			if (strPW[i] == strGuess[i])
			{
				++iAnsB;
			}
		}
		cout << iAnsA << " " << iAnsB << "\n";
	}


	return 0;
}
