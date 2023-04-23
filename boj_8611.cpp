#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isPalindrome(const vector<int>& s) {
	int i = 0, j = s.size() - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strNum;
	cin >> strNum;

	vector<vector<int>> vecNum(11, vector<int>());
	int iCount = 0;
	vector<bool> vecPalindrome(11, false);

	int iSize = strNum.length();

	for (int i = 2; i <= 10; ++i)
	{
		vector<int> vecTemp(iSize, 0);
		for (int j = 0; j < iSize; ++j)
		{
			vecTemp[j] = strNum[j] - '0';
		}
		while (true)
		{
			bool bChanged = false;
			for (int j = 0; j < iSize - 1; ++j)
			{
				if (vecTemp[j] != 0) bChanged = true;
				vecTemp[j + 1] += (vecTemp[j] % i) * 10;
				vecTemp[j] /= i;
			}

			if (vecTemp[iSize - 1] != 0) bChanged = true;
			if (bChanged)
			{
				vecNum[i].push_back(vecTemp[iSize - 1] % i);
			}
			vecTemp[iSize - 1] /= i;
			if (!bChanged) break;
		}
		if (isPalindrome(vecNum[i]))
		{
			vecPalindrome[i] = true;
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "NIE\n";
		return 0;
	}
	for (int i = 2; i <= 10; ++i)
	{
		if (vecPalindrome[i])
		{
			cout << i << " ";
			int iLen = vecNum[i].size();
			for (int j = iLen - 1; j >= 0; --j)
			{
				cout << vecNum[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
