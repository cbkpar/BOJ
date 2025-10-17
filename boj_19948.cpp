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
	
	string strLine;
	getline(cin, strLine);

	int iSpace;
	cin >> iSpace;

	vector<int> vecCount(26, 0);
	for(int i=0;i<26;++i)
	{
		cin >> vecCount[i];
	}

	int iLen = strLine.length();
	bool bFirst = true;
	string strAns = "";
	for(int i = 0;i<iLen;++i)
	{
		if(i>0 && strLine[i] == strLine[i-1]) continue;
		if(strLine[i]>='a'&&strLine[i]<='z')
		{
			vecCount[strLine[i]-'a']--;
			if(bFirst)
			{
				bFirst = false;
				strAns = strAns + (char)(strLine[i]-'a'+'A');
			}
		}
		else if(strLine[i]>='A'&&strLine[i]<='Z')
		{
			vecCount[strLine[i]-'A']--;
			if(bFirst)
			{
				bFirst = false;
				strAns = strAns + (char)(strLine[i]);
			}
		}
		else if(strLine[i] == ' ')
		{
			--iSpace;
			bFirst = true;
		}
	}

	int iAnsLen = strAns.length();
	for(int i=0;i<iAnsLen;++i)
	{
		if(i>0 && strAns[i] == strAns[i-1]) continue;
		vecCount[strAns[i]-'A']--;
	}

	bool bPossible = true;

	if(iSpace < 0)
	{
		bPossible = false;
	}

	for(int i=0;i<26;++i)
	{
		if(vecCount[i] < 0)
		{
			bPossible = false;
		}
	}

	if(bPossible)
	{
		cout << strAns << "\n";
	}
	else
	{
		cout << "-1" << "\n";
	}
	return 0;
}
