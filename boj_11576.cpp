#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

class CNumber
{
private:
	deque<int> m_vecNumber;
	int m_iBase;

public:
	CNumber(int _iN) : m_iBase(_iN) {}

	void AddNumberBack(int _iN)
	{
		m_vecNumber.push_back(_iN);
	}

	void AddNumberFront(int _iN)
	{
		m_vecNumber.push_front(_iN);
	}

	int Num2Int()
	{
		int iN = 0;
		int iBase = m_iBase;
		for_each(m_vecNumber.begin(), m_vecNumber.end(), [&iN, iBase](int _iN)->void {
			iN *= iBase;
			iN += _iN;
			});
		return iN;
	}

	void Int2Num(int _iN)
	{
		while (_iN)
		{
			m_vecNumber.push_front(_iN % m_iBase);
			_iN /= m_iBase;
		}
	}

	void PrintNumber()
	{
		cout << m_vecNumber[0];
		for_each(m_vecNumber.begin() + 1, m_vecNumber.end(), [](int _iN)->void {
			cout << " " << _iN;
			});
	}
};

int main()
{
	int iA, iB;
	cin >> iA >> iB;
	CNumber NumberA = CNumber(iA);
	CNumber NumberB = CNumber(iB);
	int iM;
	cin >> iM;
	for (int i = 0; i < iM; ++i)
	{
		int iN;
		cin >> iN;
		NumberA.AddNumberBack(iN);
	}
	int iTotal = NumberA.Num2Int();
	NumberB.Int2Num(iTotal);
	NumberB.PrintNumber();
	return 0;
}
