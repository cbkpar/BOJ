#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	string strA, strB;
	cin >> strA >> strB;

	for(int i=0;i<iN;++i)
	{
		char chA = strA[i];
		char chB = strB[i];

		if(chA == 'R' && chB == 'R') cout << "P";
		if(chA == 'R' && chB == 'S') cout << "R";
		if(chA == 'R' && chB == 'P') cout << "P";

		if(chA == 'S' && chB == 'R') cout << "R";
		if(chA == 'S' && chB == 'S') cout << "R";
		if(chA == 'S' && chB == 'P') cout << "S";

		if(chA == 'P' && chB == 'R') cout << "P";
		if(chA == 'P' && chB == 'S') cout << "S";
		if(chA == 'P' && chB == 'P') cout << "S";
	}

	cout << "\n";
	return 0;
}
