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

	while (true)
	{
		string strA, strB, strC;
		cin >> strA;
		if (strA == "#") break;
		cin >> strB >> strC;
		
		if (strB[0] == strB[1] && strB[2] == strB[3] && strB[1]!=strB[2])
		{
			cout << strB[0] << " " << strB[1] << " glued and ";
			cout << strB[2] << " " << strB[3] << " glued\n";
		}
		else if (strB[0] == strB[1])
		{
			cout << strB[0] << " " << strB[1] << " glued\n";
		}
		else if (strB[1] == strB[2])
		{
			cout << strB[1] << " " << strB[2] << " glued\n";
		}
		else if (strB[2] == strB[3])
		{
			cout << strB[2] << " " << strB[3] << " glued\n";
		}
	}
	return 0;
}
