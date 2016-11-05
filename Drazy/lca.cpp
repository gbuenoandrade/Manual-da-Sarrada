#include <bits/stdc++.h>

using namespace std;
#define DEBUG_ON 1

#define INF 0x3f3f3f3f
#define NSYNC ios::sync_with_stdio(false);
#define FOR(i,a,b) for(int i=a; i<(b); ++i)
#define FOR0(i,b) for(int i=0; i<(b); ++i)
#define TRAV(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define RTRAV(it,c) for(__typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); ++it)
#define DBG(x) if(DEBUG_ON) cout << #x << " == " << x << endl
#define DBGP(x) if(DEBUG_ON) cout << "(" << (x).first << ", " << (x).second << ")" << endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define R(x) scanf(" %d",&(x))
#define RR(x,y) scanf(" %d %d",&(x), &(y))
#define RRR(x,y,z) scanf(" %d %d %d",&(x), &(y),&(z))
#define CLR(v) memset(v, 0, sizeof(v))
#define SET(v) memset(v, -1, sizeof(v))

typedef long long ll;
typedef int int_type;
typedef pair<int_type, int_type> pii;
typedef vector<int_type> vi;
typedef vector<vi> vii;

const int MAXN = 100010;
const int LOGMAXN = 18;
vi adj[MAXN];
int par[MAXN], l[MAXN];
int p[MAXN][LOGMAXN];
int n;

void dfs(int src) {
	if(src) l[src] = l[par[src]] + 1;
	TRAV(it,adj[src]) if(par[*it]==-1) {
		par[*it] = src;
		dfs(*it);
	}
}

void preproc() {
	SET(par);
	l[0] = 0;
	par[0]=0;
	dfs(0);
	SET(p);
	for(int j=0; (1<<j)<n; ++j) FOR0(i,n) {
		if(!j) p[i][j] = par[i];
		else if(p[i][j-1]!=-1) {
			p[i][j] = p[p[i][j-1]][j-1];
		}
	}
}

int lca(int x, int y) {
	if(x==y) return x;
	if(l[x]>l[y]) swap(x,y);

	int log = 0;
	while((1<<(log+1)) <= l[y]) ++log;

	int dl = l[y] - l[x];
	if(dl) {
		for(int i=log; i>=0; --i) {
			if(dl&(1<<i)) y = p[y][i];
		}
	}
	if(x==y) return x;

	for(int i=log; i>=0; --i) {
		if(p[x][i]!=p[y][i]) {
			x = p[x][i];
			y = p[y][i];
		}
	}
	return p[x][0];
}

int main() {
	NSYNC;
	return 0;
}
