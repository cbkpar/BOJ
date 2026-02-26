#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	vector<int> vecCount(26, 0);
	
	string strLine;
	cin >> strLine;

	for (char ch : strLine)
	{
		vecCount[ch - 'A']++;
	}

	string strAns = "";
	int iCount = 0;
	for (int i = 0;i < 26;++i)
	{
		if (vecCount[i] > 0)
		{
			++iCount;
		}
		else
		{
			strAns = strAns + (char)(i + 'A');
		}
	}

	if (iCount == 26)
	{
		cout << "Alphabet Soup!" << "\n";
	}
	else
	{
		cout << strAns << "\n";
	}

	return 0;
}
