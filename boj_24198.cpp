#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
public:
	Person() : m_iAmount(0) {};
	~Person() {};

	void Eat(int iAmount)
	{
		m_iAmount += iAmount;
	}

	int getAmount() const
	{
		return m_iAmount;
	}

private:
	int m_iAmount;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Person Minsu;
	Person Yoona;

	int iN;
	cin >> iN;
	while (iN)
	{
		Yoona.Eat((iN + 1) / 2);
		iN /= 2;
		Minsu.Eat((iN + 1) / 2);
		iN /= 2;
	}
	cout << Minsu.getAmount() << " " << Yoona.getAmount() << "\n";
	return 0;
}
