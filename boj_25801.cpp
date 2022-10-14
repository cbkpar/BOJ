#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arrCount[26] = { 0, };
	
	string strWord;
	cin >> strWord;
	int iSize = strWord.length();
	for (int i = 0; i < iSize; ++i)
	{
		++arrCount[strWord[i] - 'a'];
	}

	bool bIsOdd = false;
	bool bIsEven = false;

	for (int i = 0; i < 26; ++i)
	{
		if (arrCount[i] == 0)
		{
			continue;
		}
		if (arrCount[i] % 2 == 0)
		{
			bIsEven = true;
		}
		else
		{
			bIsOdd = true;
		}
	}
	if (bIsEven && bIsOdd)
	{
		cout << "0/1\n";
	}
	else if (bIsEven)
	{
		cout << "0\n";
	}
	else
	{
		cout << "1\n";
	}
	return 0;
}
