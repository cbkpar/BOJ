#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

struct tagQuery
{
	int iUser, iTime;
	char chType;
};

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	list<tagQuery> listQuery;
	while (iM--)
	{
		tagQuery query;
		cin >> query.iUser >> query.iTime >> query.chType;
		listQuery.push_back(query);
	}
	listQuery.sort([](tagQuery o1, tagQuery o2)
	{
		if (o1.iTime == o2.iTime)
		{
			return o1.iUser < o2.iUser ? true : false;
		}
		return o1.iTime < o2.iTime ? true : false;
	});
	for (tagQuery tQuery : listQuery)
	{
		cout << tQuery.chType;
	}
	return 0;
}
