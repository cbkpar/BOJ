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
	while (iT--)
	{
		string strName;
		cin >> strName;

		if (strName == "Algorithm") cout << "204" << "\n";
		if (strName == "DataAnalysis") cout << "207" << "\n";
		if (strName == "ArtificialIntelligence") cout << "302" << "\n";
		if (strName == "CyberSecurity") cout << "B101" << "\n";
		if (strName == "Network") cout << "303" << "\n";
		if (strName == "Startup") cout << "501" << "\n";
		if (strName == "TestStrategy") cout << "105" << "\n";
	}
	return 0;
}
