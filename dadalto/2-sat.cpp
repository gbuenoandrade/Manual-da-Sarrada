//http://br.spoj.com/problems/CARDAPIO/
#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <string.h>
using namespace std;
 
list<int> sorted;
vector<int> graph[4123];
vector<int> tgraph[4123];
int scc[4123];
 
char s1[51], s2[51];
int a[1123], b[1123];
int neg[4123];
bool been[4123];
int id2;
 
void dfs(int a)
{
	been[a] = true;
	for(int i = 0; i < graph[a].size(); i++)
		if(!been[graph[a][i]])
			dfs(graph[a][i]);
	sorted.push_front(a);
}
 
void dfs2(int a)
{
	been[a] = true;
	scc[a] = id2;
	for(int i = 0; i < tgraph[a].size(); i++)
		if(!been[tgraph[a][i]])
			dfs2(tgraph[a][i]);
}
 
int
main(void)
{
	int n, t = 1;
	while(scanf("%d", &n) != EOF)
	{
		map<string,int> hash;
		sorted.clear();
		for(int i = 0; i < 4123; i++)
			graph[i].clear(), tgraph[i].clear();
		
		memset(been, 0, sizeof(been));
		memset(neg, 0, sizeof(neg));
		memset(scc, 0, sizeof(scc));
		int id = 1;
		
		for(int i = 0; i < n; i++)
		{
			scanf(" %s %s", s1, s2);
			if(hash[s1] == 0)
				hash[s1] = id++;
			if(hash[s2] == 0)
				hash[s2] = id++;
			a[i] = hash[s1], b[i] = hash[s2];
		}
		string no = "!";
		map<string,int> hash2 = hash;
		for(map<string,int>::iterator it = hash.begin(); it != hash.end(); it++)
			if((it->first)[0] != '!')
				neg[neg[it->second] = hash2[no + it->first]] = it->second;
		
		for(int i = 0; i < n; i++)
		{
			if(neg[a[i]] != 0)
				graph[neg[a[i]]].push_back(b[i]), tgraph[b[i]].push_back(neg[a[i]]);
			if(neg[b[i]] != 0)
				graph[neg[b[i]]].push_back(a[i]), tgraph[a[i]].push_back(neg[b[i]]);
		}
		
		for(int i = 1; i < id; i++)
			if(!been[i])
				dfs(i);
		
		memset(been, 0, sizeof(been));
		id2 = 1;
		for(list<int>::iterator it = sorted.begin(); it != sorted.end(); it++)
		{
			if(!been[*it])
			{
				dfs2(*it);
				id2++;
			}
		}
		bool ans = true;
		for(int i = 1; i < id; i++)
//			printf("%d\n", scc[i]);
			if(scc[neg[i]] == scc[i])
				 ans = false;
		
		printf("Instancia %d\n%s\n\n", t++, ans ? "sim" : "nao");
		
	}
 
}
