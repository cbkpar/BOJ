#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int t = 0;t < iN;++t)
	{
		string strLine;
		cin >> strLine;

		int iLen = strLine.length();

		for (int i = 0;i < iLen;++i)
		{
			if (strLine[i] == 'c')
			{
				if (i == iLen - 1)
				{
					cout << "k";
				}
				else
				{
					if (strLine[i + 1] == 'a') cout << "k";
					else if (strLine[i + 1] == 'o') cout << "k";
					else if (strLine[i + 1] == 'u') cout << "k";

					else if (strLine[i + 1] == 'b') cout << "k";
					else if (strLine[i + 1] == 'c') cout << "k";
					else if (strLine[i + 1] == 'd') cout << "k";
					else if (strLine[i + 1] == 'f') cout << "k";
					else if (strLine[i + 1] == 'g') cout << "k";
					else if (strLine[i + 1] == 'j') cout << "k";
					else if (strLine[i + 1] == 'k') cout << "k";
					else if (strLine[i + 1] == 'l') cout << "k";
					else if (strLine[i + 1] == 'm') cout << "k";
					else if (strLine[i + 1] == 'n') cout << "k";
					else if (strLine[i + 1] == 'p') cout << "k";
					else if (strLine[i + 1] == 'q') cout << "k";
					else if (strLine[i + 1] == 'r') cout << "k";
					else if (strLine[i + 1] == 's') cout << "k";
					else if (strLine[i + 1] == 't') cout << "k";
					else if (strLine[i + 1] == 'v') cout << "k";
					else if (strLine[i + 1] == 'w') cout << "k";
					else if (strLine[i + 1] == 'x') cout << "k";
					else if (strLine[i + 1] == 'z') cout << "k";

					else if (strLine[i + 1] == 'e') cout << "s";
					else if (strLine[i + 1] == 'i') cout << "s";
					else if (strLine[i + 1] == 'y') cout << "s";
					else cout << "c";
				}
			}
			else if (strLine[i] == 'h')
			{
				if (i > 0 && strLine[i - 1] == 'c')
				{
					continue;
				}
				cout << strLine[i];
			}
			else
			{
				cout << strLine[i];
			}
		}
		cout << "\n";
	}


	return 0;
}
