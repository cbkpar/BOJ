#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> getPI(const string& strWord)
{
	int iLen = strWord.length();
	vector<int> vecPI(iLen, 0);
	for (int i = 1, j = 0; i < iLen; ++i)
	{
		while (j > 0 && strWord[i] != strWord[j]) j = vecPI[j - 1];
		if (strWord[i] == strWord[j]) vecPI[i] = ++j;
	}
	return vecPI;
}

int KMP(const string& strSrc, const string& strWord)
{
	vector<int> vecPI = getPI(strWord);
	int iLenS = strSrc.length();
	int iLenW = strWord.length();

	int iCount = 0;
	for (int i = 0, j = 0; i < iLenS - 1; ++i)
	{
		while (j > 0 && strSrc[i] != strWord[j]) j = vecPI[j - 1];
		if (strSrc[i] == strWord[j])
		{
			if (j == iLenW - 1)
			{
				++iCount;
				j = vecPI[j];
			}
			else
			{
				++j;
			}
		}
	}
	return iCount;
}

int gcd(int iA, int iB)
{
	if (iB % iA == 0) return iA;
	return gcd(iB % iA, iA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	string strSrc, strWord;
	strSrc.resize(iN * 2);
	strWord.resize(iN);
	for (int i = 0; i < iN; ++i)
	{
		string strChar;
		cin >> strChar;
		strSrc[i] = strSrc[i + iN] = strChar[0];
	}
	for (int i = 0; i < iN; ++i)
	{
		string strChar;
		cin >> strChar;
		strWord[i] = strChar[0];
	}

	int iNumerator = KMP(strSrc, strWord);
	int iDenominator = iN;
	int iGCD = gcd(iNumerator, iDenominator);
	iNumerator /= iGCD;
	iDenominator /= iGCD;

	cout << iNumerator << "/" << iDenominator << "\n";
	return 0;
}
