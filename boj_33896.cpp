#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct strData
{
	string strName;
	long long lScore;
	long long lRisk;
	long long lCost;
	long long lTotal;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<strData> vecData(iN);
	for(int i=0;i<iN;++i)
	{
		cin >> vecData[i].strName;
		cin >> vecData[i].lScore;
		cin >> vecData[i].lRisk;
		cin >> vecData[i].lCost;
		vecData[i].lTotal = (vecData[i].lScore*vecData[i].lScore*vecData[i].lScore)/((vecData[i].lCost)*(vecData[i].lRisk+1));
	}

	sort(vecData.begin(), vecData.end(), [](const strData& o1, const strData& o2)->bool
	{
		if(o1.lTotal != o2.lTotal) return o1.lTotal > o2.lTotal;
		if(o1.lCost != o2. lCost) return o1.lCost < o2.lCost;
		return o1.strName.compare(o2.strName) <= 0;
	});

	cout << vecData[1].strName << "\n";
	return 0;
}
