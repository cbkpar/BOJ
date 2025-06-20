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
	vector<string> vecCommand(iN + 1, "");
	for (int i = 0;i < iN;++i)
	{
		cin >> vecCommand[i];
	}

	bool bAbsent = false;
	for (int i = 1;i <= iN;++i)
	{
		if (vecCommand[i] != "Present!" && vecCommand[i-1] != "Present!")
		{
			bAbsent = true;
			cout << vecCommand[i-1] << "\n";
		}
	}

	if (!bAbsent)
	{
		cout << "No Absences" << "\n";
	}
	return 0;
}
