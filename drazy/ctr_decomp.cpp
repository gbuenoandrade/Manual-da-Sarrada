#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define NSYNC ios::sync_with_stdio(false)
#define FOR(i,a,b) for(int i=a; i<(b); ++i)
#define FOR0(i,b) for(int i=0; i<(b); ++i)
#define DBG(x) cout << #x << " == " << x << endl
#define DBGV(v) for(int x : v) cout << x << " "; cout << endl
#define DBGP(x,y) cout << "(" << x << ", " << y << ")" << endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(a) (int)((a).size())
#define all(c) (c).begin(),(c).end()
#define R(x) scanf(" %d",&(x))
#define RR(x,y) scanf(" %d %d",&(x), &(y))
#define CLR(v) memset(v, 0, sizeof(v))
#define SET(v) memset(v, -1, sizeof(v))

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 100010;
vi adj[MAXN];
int rnd[MAXN];
int qtd[MAXN];

int dfs(int src, int par) {
	int ans = 1;
	for (int x : adj[src]) if (x!=par && !rnd[x]) ans += dfs(x, src);
	return qtd[src] = ans; 
}

void solve(int src, int crnd) {
	int ctr = src;
	int par = -1;
	int tgt = dfs(src, -1)/2;	
	while (true) {
		bool found = false;
		for (int x : adj[ctr]) if (x!=par && !rnd[x] && qtd[x]>tgt) {
			par = ctr;
			ctr = x;
			found = true;
			break;
		}
		if (!found) break;
	}
	rnd[ctr] = crnd;
	for (int x : adj[ctr]) if (!rnd[x]) solve(x,crnd+1);
}

int main() {
	NSYNC;
	int n;
	cin >> n;
	FOR0(i,n-1) {
		int x,y;
		cin >> x >> y;
		--x; --y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	solve(0, 1);
	FOR0(i,n) cout << (char)('A'-1+rnd[i]) << (i==n-1 ? '\n' : ' ');
	return 0;
}
