#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

vector<int> bucket[2123];
int bmax[2123];
int sqn, ant = 0, in = 0;

void init(int n, int q, vector<int> x)
{
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		a[i] = x[i];
	sqn = (sqrt(n) + 1.1);
	for(int i = 0; i < n; i++)
	{
		bucket[i/sqn].push_back(a[i]);
		bmax[i/sqn] = max(bmax[i/sqn], a[i]);
	}
}

int query(int t, int p, int x)
{
	int tmp = p, nx = -1, fx = -1, ans = -1, parc = 0;
	for(int j = 0; j < 1123; j++)
	{
		if(tmp - int(bucket[j].size()) <= 0)
		{
			x = x + bucket[j][tmp - 1];
			for(int k = 0; k < tmp; k++)
				if(bucket[j][k] > x)
					ans = k + 1 + (p - tmp);
			break;
		}
		tmp -= int(bucket[j].size());
	}
	if(ans != -1)
		return ans;
	tmp = p;
	for(int j = 0; j < 1123; j++)
	{
		if(tmp - int(bucket[j].size()) <= 0)
			break;
		else
		{
			if(bmax[j] > x)
				nx = j, parc = (p - tmp);
		}
		tmp -= int(bucket[j].size());
	}
	if(nx == -1)
		return 0;
	for(int j = 0; j < bucket[nx].size(); j++)
		if(bucket[nx][j] > x)
			ans = parc + j + 1;
	return ans;
}

void rebuild()
{
	vector<int> a;
	a.clear();
	for(int j = 0; j < 1123; j++)
	{
		a.insert(a.end(), bucket[j].begin(), bucket[j].end());
		bucket[j].clear();
		bmax[j] = 0;
	}
	sqn = (sqrt(int(a.size())) + 1.1);
	for(int j = 0; j < a.size(); j++)
	{
		bucket[j/sqn].push_back(a[j]);
		bmax[j/sqn] = max(bmax[j/sqn], a[j]);
	}	
}

void insert(int t, int p, int x)
{
	if(in >= sqn)
	{
		rebuild();
		in = 0;
	}
	if(t == 0)
	{
		for(int j = 0; j < 1123; j++)
		{
			if(p - int(bucket[j].size()) <= 0)
			{
				bucket[j].insert(bucket[j].begin() + p, x);
				bmax[j] = max(bmax[j], x);
				break;
			}
			p -= int(bucket[j].size());
		}
	}
	in++;
}

int
main(void)
{
	int n, t, p, x, q;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &q);
	init(n, q, a);
	for(int i = 0; i < q; i++)
	{
		scanf("%d %d %d", &t, &p, &x);
		if(t == 0)
			insert(t, p, x);
		else
			printf("%d\n", query(t, p, x));
	}
}