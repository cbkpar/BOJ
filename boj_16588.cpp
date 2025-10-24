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
	vector<int> vecCount(26, 0);

	int iLenA = strA.length();
	for(int i=0;i<iLenA;++i)
	{
		vecCount[strA[i]-'a']++;
	}

	int iLenB = strB.length();
	for(int i=0;i<iLenB;++i)
	{
		vecCount[strB[i]-'a']--;
	}

	bool bPossible = true;
	for(int i=0;i<26;++i)
	{
		if(vecCount[i] < 0)
		{
			bPossible = false;
		}
	}

	if(bPossible)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}
