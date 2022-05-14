#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	string strName;
	cin >> strName;

	auto CompareName = [=](string _strOldName)->bool
	{
		int iLenName = strName.length();
		int iLenOldName = _strOldName.length();
		for (int i = 0; i < iLenOldName; ++i)
		{
			for (int j = 1; j < iLenOldName; ++j)
			{
				if (iLenOldName > i + (iLenName - 1) * j)
				{
					for (int k = 0; k < iLenName; ++k)
					{
						if (strName[k] == _strOldName[i + j * k])
						{
							if (k + 1 == iLenName)
							{
								return true;
							}
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		return false;
	};

	int iCount = 0;
	while (iN--)
	{
		string strOldName;
		cin >> strOldName;
		iCount += CompareName(strOldName) ? 1 : 0;
	}
	cout << iCount << endl;
	return 0;
}
