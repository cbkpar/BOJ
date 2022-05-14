#include <iostream>

using namespace std;

class CObject
{
protected:
	int m_iR;
	int m_iC;

public:
	CObject(int _iR, int _iC) : m_iR(_iR), m_iC(_iC) {}
	int getRow() { return m_iR; };
	int getCol() { return m_iC; };
};

class CPlayer final : public CObject
{
private:
	int m_iD;

public:
	CPlayer(int _iR, int _iC, int _iD) : CObject(_iR, _iC), m_iD(_iD) {}
	int getDir() { return m_iD; };
};

class CMonster final : public CObject
{
public:
	CMonster(int _iR, int _iC) : CObject(_iR, _iC) {}
};

class CMap
{
private:
	int m_iR;
	int m_iC;

public:
	CMap(int _iR, int _iC) : m_iR(_iR), m_iC(_iC) {}
	bool CheckBattle(CPlayer* _pPlayer, CMonster* _pMonster)
	{
		if (m_iR != _pMonster->getRow() || 0 == (_pPlayer->getDir() + m_iR) % 2)
		{
			return true;
		}
		return false;
	}
};


int main()
{
	int iN, iM;
	cin >> iN >> iM;
	CMap* Map = new CMap(iN, iM);

	int iPC, iPD;
	cin >> iPC >> iPD;
	CPlayer* Player = new CPlayer(1, iPC, iPD);

	int iSR, iSC;
	cin >> iSR >> iSC;
	CMonster* Monster = new CMonster(iSR, iSC);

	if (Map->CheckBattle(Player, Monster))
	{
		cout << "NO..." << endl;
	}
	else
	{
		cout << "YES!" << endl;
	}

	delete Monster;
	delete Player;
	delete Map;
	return 0;
}
