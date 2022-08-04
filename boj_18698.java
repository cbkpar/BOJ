#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

typedef unsigned int _uint;

int CalcStep(string& _strStep)
{
	_uint iLength = _strStep.length();
	_uint iStep = 0;
	for (_uint i = 0; i < iLength; ++i)
	{
		if (_strStep[i] == 'D')
		{
			break;
		}
		++iStep;
	}
	return iStep;
}

int main()
{
	_uint iN;
	cin >> iN;
	for (_uint i = 0; i < iN; ++i)
	{
		string str;
		cin >> str;
		cout << CalcStep(str) << endl;
	}
	return 0;
}
