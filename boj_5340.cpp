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

	string strLine;

	vector<int> vecCount(6, 0);
	for (int i = 0; i < 6; ++i)
	{
		getline(cin, strLine);
		vecCount[i] = strLine.length();
		if (strLine[strLine.length() - 1] == ' ')
		{
			--vecCount[i];
		}
	}

	printf("Latitude %d:%d:%d\n", vecCount[0], vecCount[1], vecCount[2]);
	printf("Longitude %d:%d:%d\n", vecCount[3], vecCount[4], vecCount[5]);
	return 0;
}
