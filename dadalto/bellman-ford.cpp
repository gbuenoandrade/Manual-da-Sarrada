// find negative cycle
//http://www.spoj.com/problems/CHAMPS/
#include <stdio.h>
#include <string.h>

int a[112345], b[112345], c[112345], d[512];

int main(void)
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(d, 0x3f, sizeof(d));
		d[0] = 0;
		bool ans = true;
		for(int i = 0; i < m; c[i] *= -1, i++)
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
		for(int i = 0; i + 1 < n; i++)
			for(int j = 0; j < m; j++)
				if(d[b[j]] > d[a[j]] + c[j])
					d[b[j]] = d[a[j]] + c[j];
		for(int j = 0; j < m; j++)
			if(d[b[j]] > d[a[j]] + c[j])
				ans = false;
		printf("%c\n", ans ? 'y' : 'n');
	}
}