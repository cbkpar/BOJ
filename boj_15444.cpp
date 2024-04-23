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
	string strWord;
	cin >> strWord;

	vector<string> vecString(5, "");
	for (int i = 0;i < 5;++i)
	{
		vecString[i].assign(iN * 3, '.');
	}

	for (int i = 0;i < iN;++i)
	{
		if (strWord[i] == 'A')
		{
			vecString[0][i * 3] = '*';
			vecString[0][i * 3 + 1] = '*';
			vecString[0][i * 3 + 2] = '*';

			vecString[1][i * 3] = '*';
			vecString[1][i * 3 + 2] = '*';

			vecString[2][i * 3] = '*';
			vecString[2][i * 3 + 1] = '*';
			vecString[2][i * 3 + 2] = '*';

			vecString[3][i * 3] = '*';
			vecString[3][i * 3 + 2] = '*';

			vecString[4][i * 3] = '*';
			vecString[4][i * 3 + 2] = '*';
		}

		if (strWord[i] == 'B')
		{
			vecString[0][i * 3] = '*';
			vecString[0][i * 3 + 1] = '*';
			vecString[0][i * 3 + 2] = '*';

			vecString[1][i * 3] = '*';
			vecString[1][i * 3 + 2] = '*';

			vecString[2][i * 3] = '*';
			vecString[2][i * 3 + 1] = '*';
			vecString[2][i * 3 + 2] = '*';

			vecString[3][i * 3] = '*';
			vecString[3][i * 3 + 2] = '*';

			vecString[4][i * 3] = '*';
			vecString[4][i * 3 + 1] = '*';
			vecString[4][i * 3 + 2] = '*';
		}

		if (strWord[i] == 'C')
		{
			vecString[0][i * 3] = '*';
			vecString[0][i * 3 + 1] = '*';
			vecString[0][i * 3 + 2] = '*';

			vecString[1][i * 3] = '*';

			vecString[2][i * 3] = '*';

			vecString[3][i * 3] = '*';

			vecString[4][i * 3] = '*';
			vecString[4][i * 3 + 1] = '*';
			vecString[4][i * 3 + 2] = '*';
		}

		if (strWord[i] == 'D')
		{
			vecString[0][i * 3] = '*';
			vecString[0][i * 3 + 1] = '*';
			vecString[0][i * 3 + 2] = '*';

			vecString[1][i * 3] = '*';
			vecString[1][i * 3 + 2] = '*';

			vecString[2][i * 3] = '*';
			vecString[2][i * 3 + 2] = '*';

			vecString[3][i * 3] = '*';
			vecString[3][i * 3 + 2] = '*';

			vecString[4][i * 3] = '*';
			vecString[4][i * 3 + 1] = '*';
			vecString[4][i * 3 + 2] = '*';
		}

		if (strWord[i] == 'E')
		{
			vecString[0][i * 3] = '*';
			vecString[0][i * 3 + 1] = '*';
			vecString[0][i * 3 + 2] = '*';

			vecString[1][i * 3] = '*';

			vecString[2][i * 3] = '*';
			vecString[2][i * 3 + 1] = '*';
			vecString[2][i * 3 + 2] = '*';

			vecString[3][i * 3] = '*';

			vecString[4][i * 3] = '*';
			vecString[4][i * 3 + 1] = '*';
			vecString[4][i * 3 + 2] = '*';
		}
	}

	for (int i = 0;i < 5;++i)
	{
		cout << vecString[i] << "\n";
	}
	return 0;
}
