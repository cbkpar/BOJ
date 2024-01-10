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

	vector<int> vecX;
	vector<int> vecY;

	while (iN--)
	{
		string strWord;
		cin >> strWord;

		int iTemp = 0;
		for (char ch : strWord)
		{
			if (ch == ',')
			{
				vecX.push_back(iTemp);
				iTemp = 0;
			}
			else
			{
				iTemp *= 10;
				iTemp += ch - '0';
			}
		}
		vecY.push_back(iTemp);
	}

	sort(vecX.begin(), vecX.end());
	sort(vecY.begin(), vecY.end());

	cout << (*vecX.begin())-1 << "," << (*vecY.begin())-1 << "\n";
	cout << *(vecX.end()-1)+1 << "," << *(vecY.end()-1)+1 << "\n";

	return 0;
}
