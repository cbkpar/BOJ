#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	string strName;
	cin >> strName;
	bool bCheck = false;
	char Arrch[] = { 'q','w','e','r','t','a','s','d','f','g','z','x','c','v' };
	for (char ch : Arrch)
	{
		if (ch == strName.at(iN - 1))
		{
			bCheck = true;
		}
	}
	cout << (bCheck ? "1" : "0") << endl;
	return 0;
}
