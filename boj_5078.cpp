#include <iostream>
#include <string>
#include <list>

using namespace std;

void PrintShirt(list<string>& _listShirt, bool& _bIsFirst)
{
	for (auto iter = _listShirt.begin(); iter != _listShirt.end(); ++iter)
	{
		if (!_bIsFirst)
		{
			cout << " ";
		}
		cout << *iter;
		_bIsFirst = false;
	}
}

int main()
{
	while (true)
	{
		int iW, iH;
		cin >> iW;
		if (0 == iW)
		{
			break;
		}
		list<string> listSmall;
		list<string> listMedium;
		list<string> listLarge;
		while (iW--)
		{
			string strShirt;
			cin >> strShirt;
			switch (strShirt[0])
			{
			case 'S':
				listSmall.emplace_back(strShirt);
				break;
			case 'M':
				listMedium.emplace_back(strShirt);
				break;
			case 'L':
				listLarge.emplace_back(strShirt);
				break;
			}
		}
		cin >> iH;
		while (iH--)
		{
			string strShirt;
			cin >> strShirt;
			switch (strShirt[0])
			{
			case 'S':
				listSmall.emplace_back(strShirt);
				break;
			case 'M':
				listMedium.emplace_back(strShirt);
				break;
			case 'L':
				listLarge.emplace_back(strShirt);
				break;
			}
		}
		listSmall.sort();
		listMedium.sort();
		listLarge.sort();
		bool bIsFirst = true;
		PrintShirt(listSmall, bIsFirst);
		PrintShirt(listMedium, bIsFirst);
		PrintShirt(listLarge, bIsFirst);
		cout << endl;
	}
	return 0;
}
