//http://www.spoj.com/problems/QTREE2/
#include <stdio.h>
#include <vector>
using namespace std;
 
int n;
vector<int> graph[11234];
vector<int> cost[11234];
long long dist[11234];
int l[11234];
int p[20][11234];
int log2 = 0;
 
void dfs(int a, int parent, long long c, int h)
{
	p[0][a] = parent;
	dist[a] = c;
	l[a] = h;
	for(int i = 0; i < graph[a].size(); i++)
		if(graph[a][i] != parent)
			dfs(graph[a][i], a, c + cost[a][i], h+1);
}
 
void process()
{
	for(int i = 1; (1<<i) <= n; log2 = i, i++)
		for(int j = 1; j <= n; j++)
			p[i][j] = p[i-1][p[i-1][j]];
}
 
int nthp(int a, int x)
{
	for(int i = 0; x; i++, x >>= 1)
		if(x&1)
			a = p[i][a];
	return a;
}
 
int lca(int a, int b)
{
	if(l[a] < l[b])
		swap(a,b);
	int x = l[a]-l[b];
	a = nthp(a, x);
 
	if(a == b) return a;
 
	for(int i = log2; i >= 0; i--)
		if(p[i][a] != p[i][b])
		{
			a = p[i][a];
			b = p[i][b];
		}
	return p[0][a];
}
 
 
int
main(void)
{
	char type[20];
	int t, a, b, c, k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		log2 = 0;
		for(int i = 1; i <= n; i++)
		{
			graph[i].clear();
			cost[i].clear();
		}
		for(int i = 1; i < n; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			graph[a].push_back(b);
			cost[a].push_back(c);
			graph[b].push_back(a);
			cost[b].push_back(c);
		}
		dfs(1,1,0,0);
		process();
		while(scanf(" %s", type) && type[1] != 'O')
		{
			if(type[0] == 'D')
			{
				scanf("%d %d", &a, &b);
				int x = lca(a,b);
				printf("%lld\n", (dist[a]-dist[x])+(dist[b]-dist[x]));
			}
			else
			{
				scanf("%d %d %d", &a, &b, &k);
				int x = lca(a,b);
				k--;
				if(l[a]-l[x] >= k)
					printf("%d\n", nthp(a, k));
				else
					printf("%d\n", nthp(b, (l[a]-l[x])+(l[b]-l[x]) - k));
			}
		}
		printf("\n");
	}
	return 0;
} 
