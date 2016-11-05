#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
 
vector<int> graph[412];
bool art[412], ans;
bool been[412];
int low[412], num[412], id;
 
int dfs(int a, int p)
{
	been[a] = true;
	int comp = 0;
	num[a] = low[a] = id++;
	for(int i = 0; i < graph[a].size(); i++)
	{
		if(!been[graph[a][i]])
		{
			low[a] = min(low[a], dfs(graph[a][i], a));
			if(a != 1 && low[graph[a][i]] >= num[a])
				art[a] = ans = true;
			comp++;
		}
		else if(graph[a][i] != p)
		{
			low[a] = min(low[a], num[graph[a][i]]);
		}
	}
	if(a == 1 && comp > 1)
		art[a] = ans = true;
	return low[a];
}
 
int
main(void)
{
	int n, m, a, b, t = 1;
	while(scanf("%d %d", &n, &m) && n)
	{
		id = 0;
		ans = false;
		memset(art, 0, sizeof(art));
		memset(been, 0, sizeof(been));
		for(int i = 1; i <= n; i++)
			graph[i].clear();
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1, 1);
		printf("Teste %d\n", t++);
		if(!ans)
			printf("nenhum");
		else
			for(int i = 1; i <= n; i++)
				if(art[i])
					printf("%d ", i);
		printf("\n\n"); 
	}
} 