#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

set<pii > bridges;
vector<int> graph[112345];
bool art[112345], been[112345], check[112345];
int low[112345], num[112345], id = 1, comp[112345], out[112345];
vector<int> val[112345];
vector<int> rdm[112345];

void dfs(int a, int p)
{
	low[a] = num[a] = id++;
	been[a] = true;
	val[a].push_back(num[a]);
	rdm[a].push_back(0);
	for(int i = 0; i < graph[a].size(); i++)
	{
		if(!been[graph[a][i]])
		{
			comp[a]++;
			dfs(graph[a][i], a);
			val[a].push_back(out[graph[a][i]]);
			low[a] = min(low[a], low[graph[a][i]]);
			if(a != 1 && low[graph[a][i]] >= num[a])
			{
				art[a] = true;
				rdm[a].push_back(comp[a]);
			}
			else if(a == 1)
				rdm[a].push_back(comp[a]);
			else
				rdm[a].push_back(0);
			if(low[graph[a][i]] > num[a])
			{
				check[a] = check[graph[a][i]] = true;
				bridges.insert(pii(min(a,graph[a][i]), max(a,graph[a][i])) );
			}
		}
		else if(graph[a][i] != p && num[graph[a][i]] < low[a])
			low[a] = num[graph[a][i]];
	}
	if(a == 1 && comp[a] > 1)
		art[a] = true;
	out[a] = id-1;
}

int find(int a, int b)
{
	int c = (lower_bound(val[a].begin(), val[a].end(), num[b]) - val[a].begin());
	if(c == val[a].size() || c == 0)
		return 0;
	return rdm[a][c];
}

char ans[1523456];

int
main(void)
{
	int n, m, a, b, c, d, tp, q;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 1);
	scanf("%d", &q);
	int l = 0;
	for(int i = 0; i < q; i++)
	{
		scanf("%d", &tp);
		if(tp == 1)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if(check[c] == false || check[d] == false || bridges.find(pii(min(c,d), max(c,d))) == bridges.end())
			{
				strcat(ans+(l),"yes\n");
				l+= 4;
				continue;
			}
			if(num[c] > num[d])
				swap(c,d);
			int x = 0, y = 0;
			if(num[a] >= num[d] && num[a] <= out[d])
				x = 1;
			if(num[b] >= num[d] && num[b] <= out[d])
				y = 1;
			if(y == x)
			{
				strcat(ans+l,"yes\n");
				l+= 4;
			}
			else
			{
				strcat(ans+l,"no\n");
				l+= 3;
			}
		}
		else
		{
			scanf("%d %d %d", &a, &b, &c);
			if(!art[c])
			{
				strcat(ans+l,"yes\n");
				l+= 4;
				continue;
			}
			if(find(c, a) != find(c, b))
			{
				strcat(ans+l,"no\n");
				l+= 3;
			}
			else
			{
				strcat(ans+l,"yes\n");
				l+= 4;
			}
		}
	}
	printf("%s",ans);
}