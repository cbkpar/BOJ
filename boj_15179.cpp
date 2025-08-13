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

	string strA, strB;
	getline(cin, strA);
	getline(cin, strB);

	int iN;
	cin >> iN;

	int iScoreA = 0;
	int iScoreB = 0;

	string strResult;
	cin >> strResult;

	for (int i = 0;i < iN;++i)
	{
		if (i % 2 == 0)
		{
			if (strResult[i] == 'H') ++iScoreA;
			if (strResult[i] == 'D') iScoreA += 2;
			if (strResult[i] == 'O') ++iScoreB;
		}
		else
		{
			if (strResult[i] == 'H') ++iScoreB;
			if (strResult[i] == 'D') iScoreB += 2;
			if (strResult[i] == 'O') ++iScoreA;
		}
		if (iScoreA >= 7)
		{
			iScoreA = 7;
			break;
		}
		if (iScoreB >= 7)
		{
			iScoreB = 7;
			break;
		}
	}

	cout << strA << " " << iScoreA << " ";
	cout << strB << " " << iScoreB << ". ";

	if (iScoreA == iScoreB)
	{
		cout << "All square." << "\n";
	}
	else if (iScoreA >= 7)
	{
		cout << strA << " has won." << "\n";
	}
	else if (iScoreB >= 7)
	{
		cout << strB << " has won." << "\n";
	}
	else if (iScoreB > iScoreA)
	{
		cout << strB << " is winning." << "\n";
	}
	else
	{
		cout << strA << " is winning." << "\n";
	}

	return 0;
}
