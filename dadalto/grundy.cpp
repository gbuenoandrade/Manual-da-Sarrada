#include <stdio.h>
#include <set>
using namespace std;

int a[112345];
int tab[112345];
bool been[112345];

int pd(int n)
{
	if(n == 0)
		return 0;
	if(been[n])
		return tab[n];
	set<int> rdm;
	for(int i = 0; i < n; i++)
		rdm.insert(pd(i) ^ pd(n-i-1));
	for(int i = 0; i + 1 < n; i++)
		rdm.insert(pd(i) ^ pd(n-i-2));
	int count = 0;
	for(set<int>::iterator it = rdm.begin(); it != rdm.end(); it++)
		if(*it != count)
			break;
		else
			count++;
	been[n] = true;
	return tab[n] = count;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int n, m, ans = 0;
		scanf("%d %d", &n, &m);

		for(int i = 0; i < m; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i < m; i++)
			ans ^= pd(a[i] - a[i-1] - 1);
		ans ^= pd(a[0] - 1 + n - a[m-1]);

		printf("Case %d: %s\n", t, ans ? "yes" : "no");
	}
}