#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BigInteger
{
public:
	BigInteger() = default;
	~BigInteger() = default;

	void SetNum(int iN)
	{
		for (int i = 0; i < DIGIT; ++i)
		{
			m_arrDigit[i] = 0;
		}
		for (int i = 0; i < DIGIT; ++i)
		{
			m_arrDigit[i] = iN % 10;
			iN /= 10;
			if (iN == 0) break;
		}
	}

	void Add(const BigInteger& big)
	{
		for (int i = 0; i < DIGIT; ++i)
		{
			m_arrDigit[i] += big.GetDigit(i);
			if (m_arrDigit[i] >= 10)
			{
				m_arrDigit[i + 1] += m_arrDigit[i] / 10;
				m_arrDigit[i] %= 10;
			}
		}
	}

	void Print()
	{
		for (int i = DIGIT - 1; i >= 0; --i)
		{
			if (m_arrDigit[i] != 0)
			{
				for (int j = i; j >= 0; --j)
				{
					cout << m_arrDigit[j];
				}
				cout << "\n";
				return;
			}
		}
		cout << "0\n";
	}

	int GetDigit(int iN) const
	{
		if (iN >= DIGIT || iN < 0) return 0;
		return m_arrDigit[iN];
	}


private:
	enum { DIGIT = 100 };
	int m_arrDigit[DIGIT] = { 0, };
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<vector<BigInteger>> matBigInteger(iN, vector<BigInteger>(iN));
	matBigInteger[0][0].SetNum(1);

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			int iDist;
			cin >> iDist;
			if (iDist == 0) continue;

			int iNextR = i + iDist;
			int iNextC = j + iDist;
			if (iNextR < iN)
			{
				matBigInteger[iNextR][j].Add(matBigInteger[i][j]);
			}
			if (iNextC < iN)
			{
				matBigInteger[i][iNextC].Add(matBigInteger[i][j]);
			}

		}
	}
	matBigInteger[iN - 1][iN - 1].Print();
	return 0;
}
