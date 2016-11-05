//http://www.spoj.com/problems/ORDERSET/
#include <bits/stdc++.h>

struct node{
	int val, p, num;
	node *left, *right;

	node(int _val) : val(_val), p(rand()), num(1), left(NULL), right(NULL) {}
};

int get_num(node *root)
{
	return (root == NULL) ? 0 : root->num;
}

void update_num(node *root)
{
	root->num = get_num(root->left) + get_num(root->right) + 1;
}

node *rotate_left(node *root)
{
	node *a = root;
	node *b = root->right;

	a->right = b->left;
	b->left = a;
	update_num(a); update_num(b);
	return b;
}

node *rotate_right(node *root)
{
	node *a = root;
	node *b = root->left;

	a->left = b->right;
	b->right = a;
	update_num(a); update_num(b);
	return b;
}

node *insert(node *root, int x)
{
	if(root == NULL)
		return new node(x);
	if(x > root->val)
		root->right = insert(root->right, x);
	else if(x < root->val)
		root->left = insert(root->left, x);

	update_num(root);

	if(root->right && root->right->p > root->p)
		root = rotate_left(root);
	if(root->left && root->left->p > root->p)
		root = rotate_right(root);
	return root;
}

node *remove(node *root, int x)
{
	if(root == NULL)
		return NULL;
	if(x > root->val)
		root->right = remove(root->right, x);
	else if(x < root->val)
		root->left = remove(root->left, x);
	else if(root->left == NULL)
		root = root->right;
	else if(root->right == NULL)
		root = root->left;
	else if(root->left->p > root->right->p)
	{
		root = rotate_right(root);
		root->right = remove(root->right, x);
	}
	else
	{
		root = rotate_left(root);
		root->left = remove(root->left, x);
	}
	if(root)
		update_num(root);
	return root;
}

int kth(node *root, int k)
{
	if(get_num(root->left) >= k)
		return kth(root->left, k);
	else if(get_num(root->left) + 1 == k)
		return root->val;
	else
		return kth(root->right, k - get_num(root->left) - 1);
}

int count(node *root, int x)
{
	if(root == NULL)
		return 0;
	if(x < root->val)
		return count(root->left, x);
	else if(x == root->val)
		return get_num(root->left);
	else
		return get_num(root->left) + 1 + count(root->right, x);
}

int main(void)
{
	int q, x; char tp;
	node *root = NULL;
	scanf("%d", &q);
	while(q-- && scanf(" %c %d", &tp, &x))
	{
		if(tp == 'I')
			root = insert(root, x);
		else if(tp == 'D')
			root = remove(root, x);
		else if(tp == 'C')
			printf("%d\n", count(root, x));
		else
		{
			if(get_num(root) < x)
				printf("invalid\n");
			else
				printf("%d\n", kth(root, x));
		}
//		printf("size: %d\n", get_num(root));
	}
}