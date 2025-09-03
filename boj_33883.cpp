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
	cin >> strLine;

	int iLen = strLine.length();

	vector<int> vecA;
	vector<int> vecB;
	for (int i = 0; i < iLen; ++i)
	{
		if (strLine[i] == 'a' || strLine[i] == 'e' || strLine[i] == 'i' || strLine[i] == 'o' || strLine[i] == 'u')
		{
			vecA.push_back(i + 1);
		}
		else
		{
			vecB.push_back(i + 1);
		}
	}

	string strList = "aeiouns";

	for (char ch : strList)
	{
		if (strLine[iLen - 1] == ch)
		{
			if (vecA.size() < 2)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << vecA[vecA.size() - 2] << "\n";
			}
			return 0;
		}
	}

	if (vecA.size() < 1)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << vecA[vecA.size() - 1] << "\n";
	}
	return 0;
}
