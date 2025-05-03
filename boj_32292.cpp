#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		int iN;
		cin >> iN;

		string strWord;
		cin >> strWord;

		while (true)
		{
			if (strWord.find("ABB") == string::npos)
			{
				break;
			}
			strWord.replace(strWord.find("ABB"), 3, "BA");

		}
		cout << strWord << "\n";
	}
	return 0;
}
