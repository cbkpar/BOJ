#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

struct tagWord
{
	tagWord(string _strWord, int _iCount, int _iLength)
	{
		strWord = _strWord;
		iCount = _iCount;
		iLength = _iLength;
	}

	string strWord;
	int iCount;
	int iLength;
};

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	map<string, int> mapWord;
	for (int i = 0; i < iN; ++i)
	{
		string strWord;
		cin >> strWord;
		if (strWord.length() >= iM)
		{
			auto iter = mapWord.find(strWord);
			if (iter != mapWord.end())
			{
				iter->second += 1;
			}
			else
			{
				mapWord[strWord] = 1;
			}
		}
	}
	list<tagWord> listWord;
	for (auto& iter : mapWord)
	{
		listWord.emplace_back(tagWord(iter.first, iter.second, (iter.first).length()));
	}
	listWord.sort([](tagWord& o1, tagWord& o2)->bool {
		if (o1.iCount != o2.iCount)
		{
			return o1.iCount > o2.iCount;
		}
		else if (o1.iLength != o2.iLength)
		{
			return o1.iLength > o2.iLength;
		}
		else
		{
			return (o1.strWord).compare(o2.strWord) < 0;
		}
	});
	for (auto& iter : listWord)
	{
		cout << iter.strWord << "\n";
	}
	return 0;
}
