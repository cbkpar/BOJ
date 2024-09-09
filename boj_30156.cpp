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

	while(iN-->0)
	{
		string strWord;
		cin >> strWord;

		int iA = 0;
		int iB = 0;

		int iSize = strWord.length();
		for(int i=0;i<iSize;++i)
		{
			char ch = strWord[i];
			if(ch == 'a') ++iA;
			if(ch == 'b') ++iB;
		}

		int iAns = (iA<iB?iA:iB);
		cout << iAns << "\n";
	}

	return 0;
}
