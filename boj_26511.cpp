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

	for(int t=0;t<iN;++t)
	{
		string strWord;
		cin >> strWord;

		int iLen = strWord.length();
		vector<int> vecCount(26, 0);
		for(int i=0;i<iLen;++i)
		{
			++vecCount[strWord[i]-'a'];
		}
		sort(vecCount.begin(), vecCount.end());

		int iAns = iLen - vecCount[25] - vecCount[24];
		cout << iAns << "\n";
	}

	return 0;
}
