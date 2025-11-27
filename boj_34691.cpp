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

	while (true)
	{
		string strWord;
		cin >> strWord;
		if (strWord == "end") break;
		if (strWord == "animal") cout << "Panthera tigris" << "\n";
		if (strWord == "tree") cout << "Pinus densiflora" << "\n";
		if (strWord == "flower") cout << "Forsythia koreana" << "\n";

	}

	return 0;
}
