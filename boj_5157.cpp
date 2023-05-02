#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CompanyGroup
{
public:
	CompanyGroup() = delete;
	CompanyGroup(int iN, long long lR) : m_lCost(0), m_lRatio(lR)
	{
		m_vecTax.resize(iN + 1);
		for (int i = 0; i <= iN; ++i)
		{
			m_vecTax[i] = false;
		}
	};
	~CompanyGroup() {};

	void AddTax(int iNum)
	{
		m_vecTax[iNum] = true;
	}

	void Bonus(int iNum, long long lCost)
	{
		if (!m_vecTax[iNum]) return;
		m_lCost += (lCost * m_lRatio) / 100;
	}

	long long getCost() const
	{
		return m_lCost;
	}

private:
	long long m_lCost;
	long long m_lRatio;
	vector<bool> m_vecTax;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		if (t > 1) cout << "\n";
		cout << "Data Set " << t << ":\n";
		int iC, iB, iN;
		long long lR;
		cin >> iC >> iB >> iN >> lR;
		CompanyGroup company(iC, lR);
		while (iB--)
		{
			int iNum;
			cin >> iNum;
			company.AddTax(iNum);
		}
		while (iN--)
		{
			int iNum;
			long long lCost;
			cin >> iNum >> lCost;
			company.Bonus(iNum, lCost);
		}
		cout << company.getCost() << "\n";
	}
	return 0;
}
