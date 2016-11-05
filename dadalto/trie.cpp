#include <stdio.h>
#include <string.h>

int n, count = 0;

struct node{
	node *next[27];
	bool end;
	
	void garante(char c)
	{
		if(next[c-'a'] == NULL)
		{
			count++;
			next[c-'a'] = new node;
		}
	}
	
	void insert(char s[], int i)
	{
		if(s[i] == '\0')
			end = true;
		else
		{
			garante(s[i]);
			next[s[i]-'a']->insert(s, i+1);
		}
	}
	
	void dfs(char s[], int i)
	{
		if(end == true)
			printf("P\n");
		for(char c = 'a'; c <= 'z'; c++)
			if(next[c-'a'] && c != s[i])
			{
				printf("%c\n", c);
				next[c-'a']->dfs(s, 30);
				printf("-\n");
			}
		if(s[i])
		{
			printf("%c\n", s[i]);
			next[s[i]-'a']->dfs(s,i+1);
		}
	}
	
};


char avoid[33];

int
main(void)
{
	node *root = new node;
	char s[30];
	int tmp = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf(" %s", s);
		root->insert(s, 0);
		if(strlen(s) > tmp)
		{
			tmp = strlen(s);
			strcpy(avoid, s);
		}
	}
	printf("%d\n", n + 2*count - tmp);
	root->dfs(avoid, 0);
}