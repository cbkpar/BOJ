#include <iostream>
#include <string>

using namespace std;

class CPosFactory
{
private:
	int m_iX;
	int m_iY;

public:
	CPosFactory() {};
	void SetPos(int _iX, int _iY)
	{
		m_iX = _iX;
		m_iY = _iY;
	}
	string getPosName(int _iX, int _iY)
	{
		_iX -= m_iX;
		_iY -= m_iY;
		if (0 == _iX || 0 == _iY)
		{
			return "divisa";
		}
		if (0 > _iX && 0 > _iY)
		{
			return "SO";
		}
		if (0 > _iX && 0 < _iY)
		{
			return "NO";
		}
		if (0 < _iX && 0 > _iY)
		{
			return "SE";
		}
		if (0 < _iX && 0 < _iY)
		{
			return "NE";
		}
	}
};

int main()
{
	CPosFactory PosFactory;
	while (true)
	{
		int iK;
		cin >> iK;
		if (0 == iK) {
			break;
		}
		int iN, iM;
		cin >> iN >> iM;
		PosFactory.SetPos(iN, iM);
		while (iK--)
		{
			int iX, iY;
			cin >> iX >> iY;
			cout << PosFactory.getPosName(iX, iY) << endl;
		}
	}
	return 0;
}
