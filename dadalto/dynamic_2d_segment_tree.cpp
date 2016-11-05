#include <stdio.h>

int n, m;

long long gcd(long long X, long long Y) {
    long long tmp;
    while (X != Y && Y != 0) {
        tmp = X;
        X = Y;
        Y = tmp % Y;
    }
    return X;
}

struct nodes{
	long long val;
	nodes *left, *right;
	
	void garanteL()
	{
		if(left == NULL)
			left = new nodes;
	}
	void garanteR()
	{
		if(right == NULL)
			right = new nodes;
	}
	
	void update(int l, int r, int a, long long x)
	{
		if(l == r)
			val = x;
		else
		{
			
			int mid = (l+r)/2;
			if(a <= mid)
			{
				garanteL();
				left->update(l, mid, a, x);
			}
			else
			{
				garanteR();
				right->update(mid+1, r, a, x);
			}
			val = 0LL;
			if(left != NULL)
				val = left->val;
			if(right != NULL)
				val = gcd(val, right->val);
		}
	}
	
	void updateb(int l, int r, int a, nodes *o, nodes *p)
	{
		if(l != r)
		{
			int mid = (l+r)/2;
			if(a <= mid)
			{
				garanteL();
				left->updateb(l, mid, a, o ? o->left : o, p ? p->left : p);
			}
			else
			{
				garanteR();
				right->updateb(mid+1, r, a, o ? o->right : o, p ? p->right : p);
			}
		}
		val = 0;
		if(o)
			val = o->val;
		if(p)
			val = gcd(val, p->val);
	}
	
	long long get(int l, int r, int a, int b)
	{
		if(val == 0)
			return 0;
		if(a == l && b == r)
			return val;
		else
		{
			int mid = (l+r)/2;
			if(b <= mid)
			{
				if(left == NULL)
					return 0;
				else
					return left->get(l, mid, a, b);
			}
			else if(a > mid)
			{
				if(right == NULL)
					return 0;
				else
					return right->get(mid+1, r, a, b);
			}
			else
			{
				long long retv = 0;
				if(left != NULL)
					retv = left->get(l, mid, a, mid);
				if(right != NULL)
					retv = gcd(retv, right->get(mid+1, r, mid+1, b));
				return retv;
			}
		}
	}

};

struct nodef{
	nodes *val;
	nodef *left, *right;
	
	void garante()
	{
		if(left == NULL)
		{
			left = new nodef;
			left->garante_val();
		}
		if(right == NULL)
		{
			right = new nodef;
			right->garante_val();
		}
	}
	void garante_val()
	{
		if(val == NULL)
			val = new nodes;
	}
	
	void update(int l, int r, int a, int b, long long x)
	{
		garante_val();
		if(l == r)
			val->update(0, m, b, x);
		else
		{
			garante();
			int mid = (l+r)/2;
			if(a <= mid)
				left->update(l, mid, a, b, x);
			else
				right->update(mid+1,r,a,b,x);
			val->updateb(0, m, b, left->val, right->val);
		}
	}
	
	long long get(int l, int r, int a, int b, int c, int d)
	{
		if(val == NULL || val->val == 0)
			return 0;
		if(a == l && b == r)
			return val->get(0, m, c, d);
		else
		{
			int mid = (l+r)/2;
			if(b <= mid)
				return left->get(l, mid, a, b, c, d);
			else if(a > mid)
				return right->get(mid+1, r, a, b, c, d);
			else
				return gcd(left->get(l, mid, a, mid, c, d), right->get(mid+1, r, mid+1, b, c, d));
		}
	}
};

int
main(void)
{
	long long a;
	nodef *root = new nodef;
	int q, tp, x, y, z, w;
	scanf("%d %d %d", &n, &m, &q);
	while(q--)
	{
		scanf("%d", &tp);
		if(tp == 1)
		{
			scanf("%d %d %lld", &x, &y, &a);
			root->update(0, n, x, y, a);
		}
		else
		{
			scanf("%d %d %d %d", &x, &y, &z, &w);
			printf("%lld\n", root->get(0, n, x, z, y, w));
		}
	}
}