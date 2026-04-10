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

	int iT;
	cin >> iT;

	for (int i = 0;i < iT;++i)
	{
		string strA, strB;
		cin >> strA >> strB;

		int iPA = 0;
		int iNA = 0;
		int iPB = 0;
		int iNB = 0;
		int iLenA = strA.length();
		int iLenB = strB.length();
		for (char ch : strA)
		{
			if (ch == 'P') ++iPA;
		}
		for (int j = iLenA - 1;j >= 0;--j)
		{
			if (strA[j] != 'N') break;
			++iNA;
		}
		for (char ch : strB)
		{
			if (ch == 'P') ++iPB;
		}
		for (int j = iLenB - 1;j >= 0;--j)
		{
			if (strB[j] != 'N') break;
			++iNB;
		}
		if (iPA != iPB || iNA != iNB)
		{
			cout << "NO" << "\n";
		}
		else
		{
			cout << "YES" << "\n";
		}
	}

	return 0;
}
