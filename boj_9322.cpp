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

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		map<string,int> mapWord;
		vector<int> vecOrder(iN, 0);
		vector<string> vecWord(iN, "");
		for (int i = 0; i < iN; ++i)
		{
			string strWord;
			cin >> strWord;
			mapWord.insert({ strWord,i });
		}
		for (int i = 0; i < iN; ++i)
		{
			string strWord;
			cin >> strWord;
			vecOrder[mapWord[strWord]] = i;
		}
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecWord[i];
		}
		for (int i = 0; i < iN; ++i)
		{
			cout << vecWord[vecOrder[i]];
			cout << (i == iN - 1 ? "\n" : " ");
		}
	}
	return 0;
}
