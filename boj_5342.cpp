#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Recipt
{
public:
	Recipt() : m_iCost(0) {};
	~Recipt() {};

	void Print() const
	{
		printf("$%d.%02d\n", (m_iCost / 100), (m_iCost % 100));
	}

	void AddCost(int iCost)
	{
		m_iCost += iCost;
	}

private:
	int m_iCost;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> ItemCost;
	ItemCost.insert({ "Paper", 5799 });
	ItemCost.insert({ "Printer", 12050 });
	ItemCost.insert({ "Planners", 3125 });
	ItemCost.insert({ "Binders", 2250 });
	ItemCost.insert({ "Calendar", 1095 });
	ItemCost.insert({ "Notebooks", 1120 });
	ItemCost.insert({ "Ink", 6695 });

	Recipt newRecipt;
	while (true)
	{
		string strName;
		cin >> strName;
		if (strName == "EOI") break;

		auto iter = ItemCost.find(strName);
		if (iter != ItemCost.end())
		{
			newRecipt.AddCost((*iter).second);
		}
	}
	newRecipt.Print();
	return 0;
}
