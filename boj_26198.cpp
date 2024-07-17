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

	int iT;
	cin >> iT;
	cin.ignore();
	for (int t = 1;t <= iT;++t)
	{
		string strLine;
		getline(cin, strLine);
		
		int iSum = 0;
		for (char ch : strLine)
		{
			if (ch == 'I') iSum += 1;
			if (ch == 'V') iSum += 5;
			if (ch == 'X') iSum += 10;
			if (ch == 'L') iSum += 50;
			if (ch == 'C') iSum += 100;
			if (ch == 'D') iSum += 500;
			if (ch == 'M') iSum += 1000;
		}
		cout << iSum << "\n";
	}
	return 0;
}
