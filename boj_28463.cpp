#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<char>> matT = { {'.','O'},{'P','.'} };
vector<vector<char>> matF = { {'I','.'},{'.','P'} };
vector<vector<char>> matLz = { {'O','.'},{'.','P'} };

void Rotate(vector<vector<char>>& matrix)
{
	char chTemp = matrix[0][0];
	matrix[0][0] = matrix[0][1];
	matrix[0][1] = matrix[1][1];
	matrix[1][1] = matrix[1][0];
	matrix[1][0] = chTemp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strRot;
	cin >> strRot;

	int iCount = 0;
	if (strRot == "E") iCount = 1;
	if (strRot == "N") iCount = 2;
	if (strRot == "W") iCount = 3;

	while (iCount--)
	{
		Rotate(matT);
		Rotate(matF);
		Rotate(matLz);
	}

	vector<string> vecWord(2, "");
	for (int i = 0; i < 2; ++i) cin >> vecWord[i];

	bool bIsT = true;
	bool bIsF = true;
	bool bIsLz = true;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (vecWord[i][j] != matT[i][j]) bIsT = false;
			if (vecWord[i][j] != matF[i][j]) bIsF = false;
			if (vecWord[i][j] != matLz[i][j]) bIsLz = false;
		}
	}

	if (bIsT)
	{
		cout << "T" << "\n";
	}
	else if (bIsF)
	{
		cout << "F" << "\n";
	}
	else if (bIsLz)
	{
		cout << "Lz" << "\n";
	}
	else
	{
		cout << "?" << "\n";
	}
	return 0;
}
