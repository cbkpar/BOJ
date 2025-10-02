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

	string strA, strB;
	cin >> strA >> strB;

	string strPlusA = "";
	string strPlusB = "";

	bool bUsedA = false;
	bool bOKA = false;
	for(char ch : strA)
	{
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			strPlusA += ch;
			bUsedA = true;
		}
		else
		{
			if(bUsedA)
			{
				bOKA = true;
				break;
			}
			else
			{
				strPlusA += ch;
			}
		}
	}

	bool bUsedB = false;
	bool bOKB = false;
	for(char ch : strB)
	{
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			strPlusB += ch;
			bUsedB = true;
		}
		else
		{
			if(bUsedB)
			{
				bOKB = true;
				break;
			}
			else
			{
				strPlusB += ch;
			}
		}
	}

	if(!bOKA || !bOKB)
	{
		cout << "no such exercise" << "\n";
	}
	else
	{
		cout << strPlusA << strPlusB << "\n";
	}
	return 0;
}
