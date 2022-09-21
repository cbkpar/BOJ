#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

struct tagPlayer
{
	tagPlayer(int _iLevel, string _strName)
	{
		iLevel = _iLevel;
		strName = _strName;
	}

	int iLevel;
	string strName;
};

class CRoom
{
public:
	void Sort()
	{
		listPlayer.sort([](const tagPlayer& o1, const tagPlayer& o2)->bool
		{
			return (o1.strName).compare(o2.strName) < 0;
		});
	}

	void Print()
	{
		if (listPlayer.size() == iRoomCapacity)
		{
			cout << "Started!\n";
		}
		else
		{
			cout << "Waiting!\n";
		}
		Sort();
		for (tagPlayer& iter : listPlayer)
		{
			cout << iter.iLevel << " " << iter.strName << "\n";
		}
	}

	bool IsJoinAble(int iLevel)
	{
		if (listPlayer.size() >= iRoomCapacity)
		{
			return false;
		}
		if (iLevel < iRoomLevel - 10 || iLevel > iRoomLevel + 10)
		{
			return false;
		}
		return true;
	}

	void AddPlayer(tagPlayer tPlayer)
	{
		listPlayer.push_back(tPlayer);
	}

	void SetRoomLevel(int iLevel)
	{
		iRoomLevel = iLevel;
	}

	void SetRoomCapacity(int iCapacity)
	{
		iRoomCapacity = iCapacity;
	}

private:
	list<tagPlayer> listPlayer;
	int iRoomLevel = 0;
	int iRoomCapacity = 0;

};

int main()
{
	int iPlayer, iMaximum;
	cin >> iPlayer >> iMaximum;
	list<CRoom*> listRoom;
	for (int i = 0; i < iPlayer; ++i)
	{
		int iLevel;
		string strName;
		cin >> iLevel >> strName;
		auto iter = listRoom.begin();
		while (iter != listRoom.end())
		{
			if ((*iter)->IsJoinAble(iLevel))
			{
				(*iter)->AddPlayer(tagPlayer(iLevel, strName));
				break;
			}
			++iter;
		}
		if (iter == listRoom.end())
		{
			CRoom* pCRoom = new CRoom();
			pCRoom->SetRoomCapacity(iMaximum);
			pCRoom->SetRoomLevel(iLevel);
			pCRoom->AddPlayer(tagPlayer(iLevel, strName));
			listRoom.push_back(pCRoom);
		}
	}
	for (auto& iter : listRoom)
	{
		iter->Print();
	}
	for (auto& iter : listRoom)
	{
		delete iter;
	}

	return 0;
}
