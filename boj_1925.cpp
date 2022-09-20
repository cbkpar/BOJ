#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

struct tagPos
{
	int iX, iY;
};

int main()
{
	vector<tagPos> vecPos;
	for (int i = 0; i < 3; ++i)
	{
		int iX, iY;
		cin >> iX >> iY;
		vecPos.push_back({ iX, iY });
	}
	if ((vecPos[1].iY - vecPos[0].iY) * (vecPos[2].iX - vecPos[1].iX) == (vecPos[2].iY - vecPos[1].iY) * (vecPos[1].iX - vecPos[0].iX))
	{
		cout << "X\n";
		return 0;
	}
	vector<int> vecLength;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = i + 1; j < 3; ++j)
		{
			int idX = vecPos[i].iX - vecPos[j].iX;
			int idY = vecPos[i].iY - vecPos[j].iY;
			vecLength.push_back(idX*idX + idY*idY);
		}
	}
	sort(vecLength.begin(), vecLength.end());

	if (vecLength[0] == vecLength[1] && vecLength[1] == vecLength[2])
	{
		cout << "JungTriangle\n";
	}
	else if (vecLength[0] == vecLength[1] || vecLength[1] == vecLength[2])
	{
		if (vecLength[2] > vecLength[1] + vecLength[0])
		{
			cout << "Dunkak2Triangle\n";
		}
		else if (vecLength[2] == vecLength[1] + vecLength[0])
		{
			cout << "Jikkak2Triangle\n";
		}
		else
		{
			cout << "Yeahkak2Triangle\n";
		}
	}
	else
	{
		if (vecLength[2] > vecLength[1] + vecLength[0])
		{
			cout << "DunkakTriangle\n";
		}
		else if (vecLength[2] == vecLength[1] + vecLength[0])
		{
			cout << "JikkakTriangle\n";
		}
		else
		{
			cout << "YeahkakTriangle\n";
		}
	}
	return 0;
}
