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

	string strWord;
	cin >> strWord;

	int iSize = strWord.length();

	vector<int> vecP;
	vector<int> vecC;

	for (int i = 0;i < iSize;++i)
	{
		if (strWord[i] == 'P') vecP.push_back(i);
		if (strWord[i] == 'C') vecC.push_back(i);
	}

	int iMin = min(vecP.size(), vecC.size());
	for (int i = 0;i < iMin;++i)
	{
		swap(strWord[vecP[i]], strWord[vecC[i]]);
	}
	
	cout << strWord << "\n";
	return 0;
}
