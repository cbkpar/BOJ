#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int arrSum[6] = { 0, };
bool bVisited[12] = { false, };
int arrNum[12] = { 0, };
int arrIndex[12] = { 0, };
int iCount = 0;
bool bFound = false;

void BackTracking(int iK)
{
	if (bFound) return;
	if (iK == iCount)
	{
		for (int i = 0; i < 6; ++i) if (arrSum[i] != 26) return;
		bFound = true;
		return;
	}
	for (int i = 0; i < 12; ++i)
	{
		if (!bVisited[i])
		{
			bVisited[i] = true;
			arrNum[arrIndex[iK]] = i;
			switch (arrIndex[iK])
			{
			case 0:
				arrSum[0] += i + 1;
				arrSum[1] += i + 1;
				break;
			case 1:
				arrSum[3] += i + 1;
				arrSum[5] += i + 1;
				break;
			case 2:
				arrSum[0] += i + 1;
				arrSum[3] += i + 1;
				break;
			case 3:
				arrSum[1] += i + 1;
				arrSum[3] += i + 1;
				break;
			case 4:
				arrSum[3] += i + 1;
				arrSum[4] += i + 1;
				break;
			case 5:
				arrSum[0] += i + 1;
				arrSum[5] += i + 1;
				break;
			case 6:
				arrSum[1] += i + 1;
				arrSum[4] += i + 1;
				break;
			case 7:
				arrSum[0] += i + 1;
				arrSum[2] += i + 1;
				break;
			case 8:
				arrSum[2] += i + 1;
				arrSum[5] += i + 1;
				break;
			case 9:
				arrSum[2] += i + 1;
				arrSum[4] += i + 1;
				break;
			case 10:
				arrSum[1] += i + 1;
				arrSum[2] += i + 1;
				break;
			case 11:
				arrSum[4] += i + 1;
				arrSum[5] += i + 1;
				break;
			}
			BackTracking(iK + 1);
			if (bFound) return;
			switch (arrIndex[iK])
			{
			case 0:
				arrSum[0] -= i + 1;
				arrSum[1] -= i + 1;
				break;
			case 1:
				arrSum[3] -= i + 1;
				arrSum[5] -= i + 1;
				break;
			case 2:
				arrSum[0] -= i + 1;
				arrSum[3] -= i + 1;
				break;
			case 3:
				arrSum[1] -= i + 1;
				arrSum[3] -= i + 1;
				break;
			case 4:
				arrSum[3] -= i + 1;
				arrSum[4] -= i + 1;
				break;
			case 5:
				arrSum[0] -= i + 1;
				arrSum[5] -= i + 1;
				break;
			case 6:
				arrSum[1] -= i + 1;
				arrSum[4] -= i + 1;
				break;
			case 7:
				arrSum[0] -= i + 1;
				arrSum[2] -= i + 1;
				break;
			case 8:
				arrSum[2] -= i + 1;
				arrSum[5] -= i + 1;
				break;
			case 9:
				arrSum[2] -= i + 1;
				arrSum[4] -= i + 1;
				break;
			case 10:
				arrSum[1] -= i + 1;
				arrSum[2] -= i + 1;
				break;
			case 11:
				arrSum[4] -= i + 1;
				arrSum[5] -= i + 1;
				break;
			}
			bVisited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	cin >> strWord;
	arrNum[0] = (strWord[4] == 'x' ? -1 : strWord[4] - 'A');
	cin >> strWord;
	arrNum[1] = (strWord[1] == 'x' ? -1 : strWord[1] - 'A');
	arrNum[2] = (strWord[3] == 'x' ? -1 : strWord[3] - 'A');
	arrNum[3] = (strWord[5] == 'x' ? -1 : strWord[5] - 'A');
	arrNum[4] = (strWord[7] == 'x' ? -1 : strWord[7] - 'A');
	cin >> strWord;
	arrNum[5] = (strWord[2] == 'x' ? -1 : strWord[2] - 'A');
	arrNum[6] = (strWord[6] == 'x' ? -1 : strWord[6] - 'A');
	cin >> strWord;
	arrNum[7] = (strWord[1] == 'x' ? -1 : strWord[1] - 'A');
	arrNum[8] = (strWord[3] == 'x' ? -1 : strWord[3] - 'A');
	arrNum[9] = (strWord[5] == 'x' ? -1 : strWord[5] - 'A');
	arrNum[10] = (strWord[7] == 'x' ? -1 : strWord[7] - 'A');
	cin >> strWord;
	arrNum[11] = (strWord[4] == 'x' ? -1 : strWord[4] - 'A');

	for (int i = 0; i < 12; ++i)
	{
		if (arrNum[i] == -1)
		{
			arrIndex[iCount++] = i;
		}
		else
		{
			bVisited[arrNum[i]] = true;
			switch (i)
			{
			case 0:
				arrSum[0] += arrNum[i] + 1;
				arrSum[1] += arrNum[i] + 1;
				break;
			case 1:
				arrSum[3] += arrNum[i] + 1;
				arrSum[5] += arrNum[i] + 1;
				break;
			case 2:
				arrSum[0] += arrNum[i] + 1;
				arrSum[3] += arrNum[i] + 1;
				break;
			case 3:
				arrSum[1] += arrNum[i] + 1;
				arrSum[3] += arrNum[i] + 1;
				break;
			case 4:
				arrSum[3] += arrNum[i] + 1;
				arrSum[4] += arrNum[i] + 1;
				break;
			case 5:
				arrSum[0] += arrNum[i] + 1;
				arrSum[5] += arrNum[i] + 1;
				break;
			case 6:
				arrSum[1] += arrNum[i] + 1;
				arrSum[4] += arrNum[i] + 1;
				break;
			case 7:
				arrSum[0] += arrNum[i] + 1;
				arrSum[2] += arrNum[i] + 1;
				break;
			case 8:
				arrSum[2] += arrNum[i] + 1;
				arrSum[5] += arrNum[i] + 1;
				break;
			case 9:
				arrSum[2] += arrNum[i] + 1;
				arrSum[4] += arrNum[i] + 1;
				break;
			case 10:
				arrSum[1] += arrNum[i] + 1;
				arrSum[2] += arrNum[i] + 1;
				break;
			case 11:
				arrSum[4] += arrNum[i] + 1;
				arrSum[5] += arrNum[i] + 1;
				break;
			}
		}
	}
	BackTracking(0);

	string strAnswer;
	strAnswer.resize(9);

	for (int i = 0; i < 9; ++i) strAnswer[i] = '.';
	strAnswer[4] = arrNum[0] + 'A';
	cout << strAnswer << "\n";

	for (int i = 0; i < 9; ++i) strAnswer[i] = '.';
	strAnswer[1] = arrNum[1] + 'A';
	strAnswer[3] = arrNum[2] + 'A';
	strAnswer[5] = arrNum[3] + 'A';
	strAnswer[7] = arrNum[4] + 'A';
	cout << strAnswer << "\n";

	for (int i = 0; i < 9; ++i) strAnswer[i] = '.';
	strAnswer[2] = arrNum[5] + 'A';
	strAnswer[6] = arrNum[6] + 'A';
	cout << strAnswer << "\n";

	for (int i = 0; i < 9; ++i) strAnswer[i] = '.';
	strAnswer[1] = arrNum[7] + 'A';
	strAnswer[3] = arrNum[8] + 'A';
	strAnswer[5] = arrNum[9] + 'A';
	strAnswer[7] = arrNum[10] + 'A';
	cout << strAnswer << "\n";

	for (int i = 0; i < 9; ++i) strAnswer[i] = '.';
	strAnswer[4] = arrNum[11] + 'A';
	cout << strAnswer << "\n";

	return 0;
}
