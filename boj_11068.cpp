#include <iostream>

using namespace std;

int iArr[20];

bool isPalindrome(int iN)
{
	for (int i = 2; i <= 64; ++i)
	{
		int iNumber = iN;
		int iSize = 0;
		while (iNumber)
		{
			iArr[iSize++] = iNumber % i;
			iNumber /= i;
		}
		for (int j = 0; j < iSize; ++j)
		{
			if (iArr[j] != iArr[iSize - j - 1])
			{
				break;
			}
			if (j == iSize - 1)
			{
				return true;
			}
		}
	}
	return false;

}

int main()
{
	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		cout << (isPalindrome(iN) ? "1" : "0") << endl;
	}
	return 0;
}
