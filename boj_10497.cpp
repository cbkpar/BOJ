#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Circle
{
	int iX, iY, iR;

	bool collision(int _iX, int _iY)
	{
		return (iX - _iX) * (iX - _iX) + (iY - _iY) * (iY - _iY) <= iR * iR;
	}
};

struct Rect
{
	int iX1, iY1, iX2, iY2;
	bool collision(int _iX, int _iY)
	{
		return (iX1 <= _iX && _iX <= iX2 && iY1 <= _iY && _iY <= iY2);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<Circle> vecCircle;
	vector<Rect> vecRect;

	int iM;
	cin >> iM;
	while (iM--)
	{
		string strWord;
		cin >> strWord;

		if (strWord == "circle")
		{
			Circle tCircle;
			cin >> tCircle.iX >> tCircle.iY >> tCircle.iR;
			vecCircle.push_back(tCircle);
		}
		else
		{
			Rect tRect;
			cin >> tRect.iX1 >> tRect.iY1 >> tRect.iX2 >> tRect.iY2;
			vecRect.push_back(tRect);
		}
	}

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iX, iY;
		cin >> iX >> iY;
		int iAns = 0;
		for (Circle tCircle : vecCircle)
		{
			if (tCircle.collision(iX, iY)) ++iAns;
		}
		for (Rect tRect : vecRect)
		{
			if (tRect.collision(iX, iY)) ++iAns;
		}
		cout << iAns << "\n";
	}
	return 0;
}
