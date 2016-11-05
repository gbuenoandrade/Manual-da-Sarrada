//http://www.spoj.com/problems/NHAY/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
 
string needle;
int next[11234567];
 
int foo(int i, char c)
{
	if(i == 0)
		return (c == needle[0]) ? 1 : 0;
 
	if(needle[next[i]] == c)
		return next[i] + 1;
 
	else
		return foo(next[i], c);
}
 
void process()
{
	next[0] = 0;
	next[1] = 0;
	for(int i = 2; i <= needle.size(); i++)
		next[i] = foo(i-1, needle[i-1]);
}
 
int
main(void)
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		cin >> needle;
		scanf(" ");
		char c;
		process();
		int match = 0, i = 0;
		while((c = getchar()) != '\n')
		{
			while(c != needle[match] && match != 0)
				match = next[match];
			if(c == needle[match])
				match++;
			
			if(match == n)
				printf("%d\n", i - n + 1);
			i++;
		}
		printf("\n");
	}
} 