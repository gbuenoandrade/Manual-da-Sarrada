const int MAXN = 100010;
const int MAX_LOG = 18;
int v[MAXN];
int st[MAXN][MAX_LOG];
int logt[MAXN];
int n;

void build() {
	logt[1] = 0;
	for (int i=2, val=1; i<=n; i*=2, ++val) {
		int lim = min(2*i, n+1);
		FOR(j,i,lim) {
			logt[j] = val;
		}
	}	
	FOR0(j,MAX_LOG) FOR0(i,n) if(i + (1 << j) - 1 < n) {
		st[i][j] = (j ? min(st[i][j-1], st[i + (1 << (j-1))][j-1]): v[i]);
	}
}

int query(int l, int r) {
	int x = logt[r-l+1];
	return min(st[l][x],st[r-(1<<x)+1][x]);
}