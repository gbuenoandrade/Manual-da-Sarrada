#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int n, m;
char s1[2123], s2[2123];
int tab[2123][2123];

int pd(int i, int j)
{
	if(i == n)
		return m-j;
	if(j == m)
		return n-i;
	if(tab[i][j] != -1)
		return tab[i][j];
	return tab[i][j] = min(pd(i+1, j) + 1, min(pd(i, j+1) + 1, pd(i+1, j+1) + (s1[i] != s2[j]))); 
}

int
main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		memset(tab, 0xff,sizeof(tab));
		scanf(" %s %s", s1, s2);
		n = strlen(s1); m = strlen(s2);
		printf("%d\n", pd(0,0));
	}
	return 0;
}