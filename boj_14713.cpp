#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char Delimiter)
{
	istringstream iss(str);
	string buffer;
	vector<string> result;
	while (getline(iss, buffer, Delimiter))
	{
		result.push_back(buffer);
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	cin.ignore();
	vector<vector<string>> vecWord(iN, vector<string>());
	for (int i = 0; i < iN; ++i)
	{
		string strLine;
		getline(cin, strLine);
		vecWord[i] = split(strLine, ' ');
	}

	string strLine;
	getline(cin, strLine);
	vector<string> vecAns = split(strLine, ' ');

	vector<int> vecPos(iN, 0);
	int iSize = vecAns.size();
	bool bPossible = true;
	for (int i = 0; i < iSize; ++i)
	{
		bool bTemp = false;
		for (int j = 0; j < iN; ++j)
		{
			if (vecPos[j] < vecWord[j].size())
			{
				if (vecWord[j][vecPos[j]] == vecAns[i])
				{
					++vecPos[j];
					bTemp = true;
					break;
				}
			}
		}
		if (!bTemp)
		{
			bPossible = false;
			break;
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		if (vecWord[i].size() != vecPos[i])
		{
			bPossible = false;
		}
	}
	cout << (bPossible ? "Possible" : "Impossible") << "\n";
	return 0;
}
