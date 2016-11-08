const int MAXN = 100010;
const int MAX_LOG = 18;
int v[MAXN];
int st[MAXN][MAX_LOG];
int n;

void build() {
	for(int j = 0; j < MAX_LOG; ++j)
		for(int i = 0; i < n; ++i) if(i + (1 << j) - 1 < n)
			st[i][j] = (j ? min(st[i][j-1], st[i + (1 << (j-1))][j-1]): v[i]);
}

int query(int l, int r) {
	// int x = log2(r-l+1);
	int x=0;
	int sz = (r-l+1);
	while((1<<(x+1)) <= sz) ++x;
	return min(st[l][x],st[r-(1<<x)+1][x]);
}