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
	vector<string> vecWord;

	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;

		string strReverse = "";
		for (char ch : strWord)
		{
			strReverse = ch + strReverse;
		}
		vecWord.push_back(strReverse);
	}

	sort(vecWord.begin(), vecWord.end());

	for (int i = 0;i < iN;++i)
	{
		cout << vecWord[i] << "\n";
	}
	return 0;
}
