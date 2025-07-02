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

	int iLen;
	cin >> iLen;
	string strNum;
	cin >> strNum;

	char ch1 = ' ';
	char ch2 = ' ';

	for(int i=0;i<iLen;++i)
	{
		if(ch1 == 'P' && ch2 == 'S')
		{
			if(strNum[i] == '4' || strNum[i] == '5') continue;
		}
		cout << strNum[i];
		ch1 = ch2;
		ch2 = strNum[i];
	}
	cout << "\n";
	return 0;
}
