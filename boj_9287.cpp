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
	for (int t = 1; t <= iT; ++t)
	{
		int iH;
		cin >> iH;
		vector<string> vecFloor(iH, "");
		for (int i = 0; i < iH; ++i) cin >> vecFloor[i];
		bool bPossible = true;
		for (int i = 0; i < iH; ++i)
		{
			if (vecFloor[i][0] == '0' && vecFloor[i][1] == '0') bPossible = false;
			if (vecFloor[i][1] == '0' && vecFloor[i][2] == '0') bPossible = false;
		}

		cout << "Case " << t << ": " << (bPossible ? "Standing" : "Fallen") << "\n";
	}
	return 0;
}
