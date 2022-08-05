#include <iostream>

using namespace std;

typedef struct Circle
{
	int iX;
	int iY;
	int iR;
}CIRCLE;

void InputData(CIRCLE& circle)
{
	cin >> circle.iX >> circle.iY >> circle.iR;
}

int CalcIntersect(CIRCLE& c1, CIRCLE& c2)
{
	int idX = c1.iX - c2.iX;
	int idY = c1.iY - c2.iY;
	int iDist = idX * idX + idY * idY;
	if (c1.iX == c2.iX && c1.iY == c2.iY && c1.iR == c2.iR)
	{
		return -1;
	}
	else if (iDist == (c1.iR + c2.iR) * (c1.iR + c2.iR))
	{
		return 1;
	}
	else if (iDist == (c1.iR - c2.iR) * (c1.iR - c2.iR))
	{
		return 1;
	}
	else if (iDist < (c1.iR - c2.iR) * (c1.iR - c2.iR))
	{
		return 0;
	}
	else if (iDist < (c1.iR + c2.iR) * (c1.iR + c2.iR))
	{
		return 2;
	}
	return 0;
}

int main()
{
	int iT;
	cin >> iT;
	while (iT--)
	{
		CIRCLE circle1, circle2;
		InputData(circle1);
		InputData(circle2);
		cout << CalcIntersect(circle1, circle2) << endl;
	}
	return 0;
}
