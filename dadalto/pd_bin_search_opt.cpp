#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

#define inf 0x3f3f3f3f

int a[1123];
int cost[1123][1123];
int tab[1123][1123];

int pd(int n, int k)
{
	if(n == 0)
		return 0;
	if(k == 0)
		return cost[1][n];
	int retv = inf;
	for(int i = 0; i < n; i++)
		retv = min(retv, pd(i, k-1) + cost[i+1][n]);
	return retv;
}

void compute(int k, int l, int r, int a, int b)
{
	if(r < l)
		return;
	int mid = (l+r) / 2;
	int opt = -1;
	for(int i = a; i <= b && i < mid; i++)
		if(tab[i][k-1] + cost[i+1][mid] < tab[mid][k])
			tab[mid][k] = tab[i][k-1] + cost[i+1][mid], opt = i;

	if(l != r)
		compute(k, l, mid - 1, a, opt), compute(k, mid + 1, r, opt, b);
}

int main(void)
{
	int n, m;
	while(scanf("%d %d", &n, &m) && n)
	{
		for(int i = 1; i <= n; a[i] += a[i-1], i++)
			scanf("%d", &a[i]);

		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				cost[i][j] = cost[i][j-1] + ((a[j-1] - a[i-1]) * (a[j] - a[j-1]));

		memset(tab, 0x3f, sizeof(tab));
		for(int i = 0; i <= m; i++)
			tab[0][i] = 0;
		for(int i = 1; i <= n; i++)
			tab[i][0] = cost[1][i];

		for(int i = 1; i <= m; i++)
			compute(i, 1, n, 0, n-1);
		printf("%d\n", tab[n][m]);
	}
}