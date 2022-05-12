#include <iostream>
#include <string>

using namespace std;

int CheckWolf(string _str)
{
	string::iterator iter = _str.begin();
	while (iter != _str.end())
	{
		int iW = 0;
		while (iter != _str.end())
		{
			if ('w' != *iter) {
				break;
			}
			++iW;
			++iter;
		}
		int iO = 0;
		while (iter != _str.end())
		{
			if ('o' != *iter) {
				break;
			}
			++iO;
			++iter;
		}
		if (iW != iO)
		{
			return 0;
		}
		int iL = 0;
		while (iter != _str.end())
		{
			if ('l' != *iter) {
				break;
			}
			++iL;
			++iter;
		}
		if (iW != iL)
		{
			return 0;
		}
		int iF = 0;
		while (iter != _str.end())
		{
			if ('f' != *iter) {
				break;
			}
			++iF;
			++iter;
		}
		if (iW != iF)
		{
			return 0;
		}
	}
	return 1;
}


int main()
{
	string str;
	cin >> str;
	cout << CheckWolf(str) << endl;
	return 0;
}
