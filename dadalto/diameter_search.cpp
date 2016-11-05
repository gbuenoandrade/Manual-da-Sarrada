//http://wcipeg.com/problem/coci081p6
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define MAXN 312345

vector<int> graph[MAXN];
bool inq[MAXN];
int n;
int been[MAXN];
int h1[MAXN], h2[MAXN];
int p1[21][MAXN], p2[21][MAXN];
int log = 0;
multimap<int,int> tree1, tree2;

int bfs(int a)
{
	memset(inq, 0, sizeof(inq));
	queue<int> q;
	q.push(a);
	inq[a] = true;
	while(!q.empty())
	{
		a = q.front();
		q.pop();
		for(int i = 0; i < graph[a].size(); i++)
			if(!inq[graph[a][i]])
			{
				q.push(graph[a][i]);
				inq[graph[a][i]] = true;
			}
	}
	return a;
}

void dfs(int a, int p, int d, int h[], int pa[])
{
	h[a] = d;
	pa[a] = p;
	for(int i = 0; i < graph[a].size(); i++)
		if(graph[a][i] != p)
			dfs(graph[a][i], a, d+1, h, pa);
}

void process(int p[][MAXN])
{
	for(int i = 1; i <= log; i++)
		for(int j = 1; j <= n; j++)
			p[i][j] = p[i-1][p[i-1][j]];
}

int nthp(int a, int x, int p[][MAXN])
{
	for(int i = 0; x;  x>>= 1, i++)
		if(x&1)
			a = p[i][a];
	return a;
}

void change(int a, int p)
{
	been[a] = true;
	tree1.insert(pair<int,int> (h1[a], a));
	tree2.erase(tree2.find(h2[a]));
	for(int i = 0; i < graph[a].size(); i++)
		if(!been[graph[a][i]] && graph[a][i] != p)
			change(graph[a][i], a); 
}

int
main(void)
{
	int a, b;
	scanf("%d", &n);
	for(int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int d1 = bfs(1); int d2 = bfs(d1);
	dfs(d1,d1,0, h1, p1[0]);
	dfs(d2,d2,0, h2, p2[0]);
	for(int i = 0; (1<<i) <= n; log = i, i++);
	process(p1);process(p2);
	for(int i = 1; i <= n; i++)
		tree2.insert(pair<int,int> (h2[i], i));
	int ans = h1[d2];
	for(int i = 0; nthp(d1,i,p2) != d2; i++)
	{
		int x = nthp(d1,i,p2);
		change(x, p2[0][x]);
		ans = min(ans, max(max(((tree1.rbegin())->first + 1)/2 + ((tree2.rbegin())->first + 1)/2 + 1, (tree1.rbegin())->first), (tree2.rbegin())->first) );
	}
	printf("%d\n", ans);
	return 0;
}



















