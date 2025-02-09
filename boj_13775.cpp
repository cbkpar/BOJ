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

	cin.ignore();
	string strLine;
	getline(cin, strLine);

	int iLen = strLine.length();
	for(int i=0;i<iLen;++i)
	{
		if(strLine[i] >= 'a' && strLine[i] <= 'z')
		{
			cout << (char)((strLine[i]-'a'+26000-iN)%26+'a');
			++iN;
			if(iN==26) iN = 1;
		}
		else
		{
			cout << strLine[i];
		}
	}
	cout << "\n";

	return 0;
}
