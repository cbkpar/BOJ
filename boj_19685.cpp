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

	long long lS, lE;
	cin >> lS >> lE;
	for (long long i = lS;i <= lE;++i)
	{
		vector<int> vecNum;
		long long lTemp = i;
		while (lTemp > 0)
		{
			vecNum.push_back(lTemp % 10);
			lTemp /= 10;
		}

		bool bPalindrome = true;
		int iLen = vecNum.size();
		for (int j = 0;j < iLen;++j)
		{
			if (vecNum[j] != vecNum[iLen - 1 - j])
			{
				bPalindrome = false;
			}
		}

		if (bPalindrome)
		{
			cout << "Palindrome!" << "\n";
		}
		else
		{
			cout << i << "\n";
		}
	}

	return 0;
} 
