#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool CheckCount(string _strA, string _strB)
{
	int iCount[26];
	for (int i = 0; i < 26; ++i)
	{
		iCount[i] = 0;
	}
	for_each(_strA.begin(), _strA.end(),
		[&iCount](char c)->void { ++iCount[c - 'a']; });
	for_each(_strB.begin(), _strB.end(),
		[&iCount](char c)->void { --iCount[c - 'a']; });
	for (int i = 0; i < 26; ++i)
	{
		if (0 != iCount[i])
		{
			return false;
		}
	}
	return true;
}

bool CheckFirstLast(string _strA, string _strB)
{
	if (*_strA.begin() != *_strB.begin())
	{
		return false;
	}
	if (*(_strA.end() - 1) != *(_strB.end() - 1))
	{
		return false;
	}
	return true;
}

bool CheckRemoveVowel(string _strA, string _strB)
{
	auto iterA = _strA.begin();
	auto iterB = _strB.begin();
	auto CheckVowel = [](char c) {
		switch (c)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
		}
	};
	while (iterA != _strA.end())
	{
		while (iterA != _strA.end())
		{
			if (CheckVowel(*iterA))
			{
				++iterA;
			}
			else
			{
				break;
			}
		}
		while (iterB != _strB.end())
		{
			if (CheckVowel(*iterB))
			{
				++iterB;
			}
			else
			{
				break;
			}
		}
		if (iterA == _strA.end())
		{
			return true;
		}
		else
		{
			if (*iterA != *iterB)
			{
				return false;
			}
			++iterA;
			++iterB;
		}
	}
	return true;
}

int main()
{
	int iN;
	cin >> iN;
	string strA;
	cin >> strA;
	string strB;
	cin >> strB;

	if (CheckCount(strA, strB))
	{
		if (CheckFirstLast(strA, strB))
		{
			if (CheckRemoveVowel(strA, strB))
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
