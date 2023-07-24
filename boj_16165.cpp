#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int iN, iM;
	cin >> iN >> iM;
	
	map<string, string> mapGroup;
	map<string, vector<string>> mapName;
	
	while(iN--)
	{
	    string strTeam;
	    cin >> strTeam;
	    
	    int iMemberCount;
	    cin >> iMemberCount;
	    while(iMemberCount--)
	    {
	        string strName;
	        cin >> strName;
	        
	        mapGroup[strName] = strTeam;
	        mapName[strTeam].push_back(strName);
	    }
	}
	
	while(iM--)
	{
	    string strWord;
	    int iType;
	    cin >> strWord >> iType;
	    if(iType == 0)
	    {
	        vector<string> vecAns;
	        for(string strName : mapName[strWord])
	        {
	            vecAns.push_back(strName);
	        }
	        sort(vecAns.begin(), vecAns.end());
	        for(string strName : vecAns)
	        {
	            cout << strName << "\n";
	        }
	    }
	    else
	    {
	        cout << mapGroup[strWord] << "\n";
	    }
	}
	return 0;
}
