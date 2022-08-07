#include <iostream>
#include <string>

using namespace std;

bool CheckJava(string& _strName)
{
	int iSize = _strName.length();
	if (_strName[0] >= 'A' && _strName[0] <= 'Z')
	{
		return false;
	}
	for (int i = 0; i < iSize; ++i)
	{
		if (_strName[i] == '_')
		{
			return false;
		}
	}
	return true;
}

bool CheckCpp(string& _strName)
{
	int iSize = _strName.length();
	if (_strName[0] == '_' || _strName[iSize - 1] == '_')
	{
		return false;
	}
	if (_strName[0] >= 'A' && _strName[0] <= 'Z')
	{
		return false;
	}
	for (int i = 1; i < iSize; ++i)
	{
		if (_strName[i] >= 'A' && _strName[i] <= 'Z')
		{
			return false;
		}
		if (_strName[i - 1] == '_' && _strName[i] == '_')
		{
			return false;
		}
	}
	return true;
}

void PrintToCpp(string& _strName)
{
	int iSize = _strName.length();
	for (int i = 0; i < iSize; ++i)
	{
		if (_strName[i] >= 'A' && _strName[i] <= 'Z')
		{
			cout << "_" << char(_strName[i] - ('A' - 'a'));
		}
		else
		{
			cout << _strName[i];
		}
	}
	cout << endl;
}

void PrintToJava(string& _strName)
{
	int iSize = _strName.length();
	for (int i = 0; i < iSize; ++i)
	{
		if (_strName[i] == '_')
		{
			++i;
			cout << char(_strName[i] + ('A' - 'a'));
		}
		else
		{
			cout << _strName[i];
		}
	}
	cout << endl;
}

int main()
{
	string strName;
	cin >> strName;
	if (CheckJava(strName))
	{
		PrintToCpp(strName);
	}
	else if (CheckCpp(strName))
	{
		PrintToJava(strName);
	}
	else
	{
		cout << "Error!" << endl;
	}
	return 0;
}
