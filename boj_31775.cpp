#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	bool bGlobal = false;
	vector<int> vecCount(26, 0);
	for(int i=0;i<3;++i)
	{
		string strWord;
		cin >> strWord;
		if(strWord[0]>='a'&&strWord[0]<='z')
		{
			++vecCount[strWord[0]-'a'];
		}
	}
	if(vecCount['l'-'a'] == 1 && vecCount['k'-'a'] == 1 && vecCount['p'-'a'] == 1)
	{
		bGlobal = true;
	}
	if(bGlobal)
	{
		cout << "GLOBAL" << "\n";
	}
	else
	{
		cout << "PONIX" << "\n";
	}
	return 0;
}
