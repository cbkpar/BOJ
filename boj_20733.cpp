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

	string strWord;
	cin >> strWord;
	
	int iLen = strWord.length();
	int iLenTriple = iLen / 3;
	for (int i = 0; i < iLenTriple; ++i)
	{
		vector<char> vecTemp;
		vecTemp.push_back(strWord[i]);
		vecTemp.push_back(strWord[iLenTriple+i]);
		vecTemp.push_back(strWord[iLenTriple*2+i]);
		sort(vecTemp.begin(), vecTemp.end());
		cout << vecTemp[1];
	}
	cout << "\n";
	return 0;
}
