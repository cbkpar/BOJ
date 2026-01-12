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

	string strWord;
	cin >> strWord;

	int iLen = strWord.length();
	vector<string> vecWord;
	for (int i = 0;i < iLen;++i)
	{
		for (int j = i + 1;j <= iLen;++j)
		{
			vecWord.push_back(strWord.substr(i, j - i));
		}
	}
	sort(vecWord.begin(), vecWord.end());
	int iSize = vecWord.size();
	cout << vecWord[iSize - 1] << "\n";

	return 0;
}
