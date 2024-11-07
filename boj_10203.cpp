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
	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;

		int iCount = 0;
		for (char ch : strWord)
		{
			if (ch == 'a') ++iCount;
			if (ch == 'e') ++iCount;
			if (ch == 'i') ++iCount;
			if (ch == 'o') ++iCount;
			if (ch == 'u') ++iCount;
		}
		cout << "The number of vowels in " << strWord << " is " << iCount << ".\n";
	}

	return 0;
}
