#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool Visited[51][51][51][3][3] = { false, };

bool dfs(int iA, int iB, int iC, int iPrev1, int iPrev2)
{
	if (Visited[iA][iB][iC][iPrev1][iPrev2]) return false;
	if (iA == 0 && iB == 0 && iC == 0) return true;
	Visited[iA][iB][iC][iPrev1][iPrev2] = true;

	if (iA > 0 && dfs(iA - 1, iB, iC, 0, iPrev1))
	{
		cout << "A";
		return true;
	}
	if (iB > 0 && iPrev1 != 1 && dfs(iA, iB - 1, iC, 1, iPrev1))
	{
		cout << "B";
		return true;
	}
	if (iC > 0 && iPrev1 != 2 && iPrev2 != 2 && dfs(iA, iB, iC - 1, 2, iPrev1))
	{
		cout << "C";
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strHistory;
	cin >> strHistory;

	int iA = 0;
	int iB = 0;
	int iC = 0;

	for (char ch : strHistory)
	{
		if (ch == 'A') ++iA;
		if (ch == 'B') ++iB;
		if (ch == 'C') ++iC;
	}

	if (dfs(iA, iB, iC, 0, 0))
	{
		cout << "\n";
	}
	else
	{
		cout << "-1" << "\n";
	}
	return 0;
}
