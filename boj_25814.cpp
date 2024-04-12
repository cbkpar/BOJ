#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int CalcScore(string strWord)
{
	int iLen = strWord.length();
	int iSum = 0;
	for (int i = 0;i < iLen;++i)
	{
		iSum += strWord[i] - '0';
	}
	return iLen * iSum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strA, strB;
	cin >> strA >> strB;

	int iA = CalcScore(strA);
	int iB = CalcScore(strB);

	int iAns = 0;
	if (iA > iB) iAns = 1;
	if (iA < iB) iAns = 2;

	cout << iAns << "\n";
	return 0;
}
