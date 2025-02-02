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

	vector<string> vecWord;
	map<string, int> mapCount;

	int iTotal = 0;

	while (true)
	{
		string strWord;
		getline(cin, strWord);

		if (strWord == "0") break;

		mapCount[strWord] = mapCount[strWord] + 1;

		if (mapCount[strWord] == 1)
		{
			vecWord.push_back(strWord);
		}
		++iTotal;
	}

	for (string strWord : vecWord)
	{
		cout << strWord << ": " << mapCount[strWord] << "\n";
	}
	cout << "Grand Total: " << iTotal << "\n";
	return 0;
}
