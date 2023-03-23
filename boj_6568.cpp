#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Fetch(string str)
{
	int iSum = 0;
	for (char ch : str)
	{
		iSum <<= 1;
		iSum += ch - '0';
	}
	return iSum;
}

void Decode(const int command, int& _operator, int& _operand)
{
	_operator = command >> 5;
	_operand = command % 32;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecMemory(32, 0);
	int iIndex = 0;

	string strCommand;
	while (cin >> strCommand)
	{
		vecMemory[iIndex] = Fetch(strCommand);
		iIndex = (iIndex + 1) % 32;

		if (iIndex == 0)
		{
			int iPC = 0;
			int iSum = 0;

			while (iPC >= 0)
			{
				int iTempPC = iPC;
				int iOperator, iOperand;
				Decode(vecMemory[iPC], iOperator, iOperand);
				iPC = (iPC + 1) % 32;
				switch (iOperator)
				{
				case 0: vecMemory[iOperand] = iSum; break;
				case 1: iSum = vecMemory[iOperand]; break;
				case 2: iPC = (iSum == 0 ? iOperand : iPC); break;
				case 3: break;
				case 4: if (--iSum < 0) iSum += 256; break;
				case 5: iSum = (++iSum) % 256; break;
				case 6: iPC = iOperand; break;
				case 7: iPC = -1; break;
				}
			}

			for (int i = 7; i >= 0; --i)
			{
				cout << ((iSum & (1 << i)) == (1 << i) ? "1" : "0");
			}
			cout << "\n";
		}
	}
	return 0;
}
