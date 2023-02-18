#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool IsFix(string strA, string strB)
{
	int iSizeA = strA.length();
	int iSizeB = strB.length();

	if (iSizeA >= iSizeB)
	{
		for (int i = 0; i < iSizeB; ++i)
		{
			if (strA[i] != strB[i]) break;
			if (i == iSizeB - 1) return true;
		}
		for (int i = 0; i < iSizeB; ++i)
		{
			if (strA[iSizeA - iSizeB + i] != strB[i]) break;
			if (i == iSizeB - 1) return true;
		}
	}
	else
	{
		for (int i = 0; i < iSizeA; ++i)
		{
			if (strB[i] != strA[i]) break;
			if (i == iSizeA - 1) return true;
		}
		for (int i = 0; i < iSizeA; ++i)
		{
			if (strB[iSizeB - iSizeA + i] != strA[i]) break;
			if (i == iSizeA - 1) return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;

	while (iT--)
	{
		vector<string> arrWord(3);
		for (int i = 0; i < 3; ++i) cin >> arrWord[i];
		bool bIsFix = false;
		if (IsFix(arrWord[0], arrWord[1])) bIsFix = true;
		if (IsFix(arrWord[1], arrWord[2])) bIsFix = true;
		if (IsFix(arrWord[2], arrWord[0])) bIsFix = true;
		cout << (bIsFix ? "No\n" : "Yes\n");
	}

	return 0;
}
