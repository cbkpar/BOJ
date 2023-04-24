#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

	map<string, int> mapName;

	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		string strName;
		cin >> strName;
		mapName.insert({ strName,0 });
	}
	cin.ignore();
	for (int i = 0; i < iN; ++i)
	{
		string strLine;
		getline(cin, strLine);
		vector<string> result = split(strLine, ' ');
		for (string str : result)
		{
			++mapName[str];
		}
	}
	vector<pair<string, int>> vecAns(iN, { "",0 });
	int iIndex = 0;
	for (auto iter : mapName)
	{
		vecAns[iIndex].first = iter.first;
		vecAns[iIndex].second = iter.second;
		++iIndex;
	}
	sort(vecAns.begin(), vecAns.end(), [](const pair<string, int>& o1, const pair<string, int>& o2)->bool
		{
			if (o1.second == o2.second) return o1.first.compare(o2.first) < 0;
			return o1.second > o2.second;
		});
	for (int i = 0; i < iN; ++i)
	{
		cout << vecAns[i].first << " " << vecAns[i].second << "\n";
	}
	return 0;
}
