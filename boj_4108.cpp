#include <iostream>

using namespace std;

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };

int calcMine(char* map, int y, int x, int n, int m)
{
	int iMine = 0;
	for (int i = 0; i < 8; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny <0 || ny>n - 1 || nx<0 || nx>m - 1) {
			continue;
		}
		if ('*' == map[ny * 100 + nx]) {
			++iMine;
		}
	}
	return iMine;
}

int main()
{
	char map[100][100];

	while (true) {
		int n, m;
		cin >> n >> m;
		if (0 == n && 0 == m)
		{
			break;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> map[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int iMine = calcMine((char *)map, i, j, n, m);
				if ('*' == map[i][j])
				{
					cout << '*';
				}
				else
				{
					cout << iMine;
				}
			}
			cout << endl;
		}
	}
	return 0;
}
