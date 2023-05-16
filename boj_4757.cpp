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

	int iAnsSolve = -1;
	int iAnsPenalty = 0;
	string strAns = "";

	while (iN--)
	{
		string strName;
		cin >> strName;

		int iTotalSolve = 0;
		int iTotalPenalty = 0;
		for (int i = 0; i < 4; ++i)
		{
			int iSubmit, iTime;
			cin >> iSubmit >> iTime;
			if (iTime> 0)
			{
				++iTotalSolve;
				iTotalPenalty += iTime + (iSubmit - 1) * 20;
			}
		}
		if (iTotalSolve > iAnsSolve)
		{
			iAnsSolve = iTotalSolve;
			iAnsPenalty = iTotalPenalty;
			strAns = strName;
		}
		else if (iTotalSolve == iAnsSolve)
		{
			if (iTotalPenalty < iAnsPenalty)
			{
				iAnsPenalty = iTotalPenalty;
				strAns = strName;
			}
		}
	}
	cout << strAns << " " << iAnsSolve << " " << iAnsPenalty << "\n";
	return 0;
}
