#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, string> mapWord;
	
	int iT;
	cin >> iT;
	for (int t = 0; t < iT; ++t)
	{
		string strA, strB;
		cin >> strA >> strB;
		mapWord[strB] = strA;
	}

	string strWord;
	cin >> strWord;

	int iLen = strWord.length();
	for (int i = 0; i < iLen; i += 4)
	{
		string strTemp = "";
		strTemp = strTemp + strWord[i];
		strTemp = strTemp + strWord[i+1];
		strTemp = strTemp + strWord[i+2];
		strTemp = strTemp + strWord[i+3];

		if (mapWord.find(strTemp) == mapWord.end())
		{
			cout << "?";
		}
		else
		{
			cout << mapWord[strTemp];
		}
	}
	cout << "\n";
	return 0;
}
