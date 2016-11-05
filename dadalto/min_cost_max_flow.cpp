//http://www.spoj.com/problems/SPHIWAY/
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

struct edge{
	int dest, cap, re, cost;
	edge(int x, int y, int z, int w) : dest(x), cap(y), re(z), cost(w){}
};

vector<edge> graph[112345];

bool been[11234];
int p[112345];
int e_used[112345];
long long dist[11234];
typedef pair<long long, int> pli;
#define inf 0x3f3f3f3f3f3f3f3fLL

bool dijkstra(int s, int t) // not dijkstra
{
	memset(been, 0, sizeof(been));
	memset(dist, 0x3f, sizeof(dist));
	queue<int> q;
	dist[s] = 0;
	p[s] = s;
	q.push(s);
	bool retv = false;
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		been[a] = false;
		if(a == t)
			retv = true;
		for(int i = 0; i < graph[a].size(); i++)
			if(graph[a][i].cap && dist[graph[a][i].dest] > dist[a] + graph[a][i].cost)
			{
				dist[graph[a][i].dest] = dist[a] + graph[a][i].cost;
				p[graph[a][i].dest] = a;
				e_used[graph[a][i].dest] = i;
				if(!been[graph[a][i].dest])
					q.push(graph[a][i].dest);
				been[graph[a][i].dest] = true;
			}
	}
	return retv;
}

pli mincost_maxflow(int s, int t)
{
	pli retv = pli(0,0);
	while(dijkstra(s, t))
	{
		retv.first += dist[t];
		int x = 0x3f3f3f3f;
		for(int i = t; p[i] != i; i = p[i])
			x = min(x, graph[p[i]][e_used[i]].cap);
		for(int i = t; p[i] != i; i = p[i])
			graph[p[i]][e_used[i]].cap -= x, graph[i][graph[p[i]][e_used[i]].re].cap += x;
		retv.second += x;
	}
	return retv;
}

int main(void)
{
	int n, m, s, t, a, b, c;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(edge(b, 1, graph[b].size(), c));
		graph[b].push_back(edge(a, 0, graph[a].size() - 1, -1*c));

		graph[b].push_back(edge(a, 1, graph[a].size(), c));
		graph[a].push_back(edge(b, 0, graph[b].size() - 1, -1*c));
	}
	graph[0].push_back(edge(s, 2, graph[s].size(), 0));
	graph[s].push_back(edge(0, 0, graph[0].size() - 1, 0));

	pli ans = mincost_maxflow(0, t);
	if(ans.second == 2)
		printf("%lld\n", ans.first);
	else
		printf("-1\n");
}