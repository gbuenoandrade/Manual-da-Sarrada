
#include <stdio.h>
#include <vector>
using namespace std;
 
int a[1123456];
int l[1123456];
int r[1123456];
 
int
main(void)
{
	int n;
	while(scanf("%d", &n) && n)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		long long ans = 0;
		for(int i = 1; i <= n; i++)
		{
			int x = i-1;
			while(a[i] <= a[x] && x != 0)
				x = l[x];
			l[i] = x;	
		}
		r[n+1] = n+1; 
		for(int i = n; i > 0; i--)
		{
			int x = i+1;
			while(a[i] <= a[x] && x != n + 1)
				x = r[x];
			r[i] = x;	
		}
		for(int i = 1; i <= n; i++)
			ans = max(ans, (r[i] - l[i] - 1LL) * a[i]);
		printf("%lld\n", ans);
	}	
} 