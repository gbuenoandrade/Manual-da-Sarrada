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

const int MAXN = 100010;
vi adj[MAXN];
int d[MAXN], low[MAXN], visi[MAXN], t;
bool art[MAXN];
set<pii> bs;

void dfs(int u, int p=-1) {
	visi[u] = true;
	d[u] = low[u] = t++;
	bool found = false;
	int ct=0;
	for(auto v : adj[u]) {
		if(!visi[v]) {
			++ct;
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v]>=d[u]) found = true;
			if(low[v]>d[u]) bs.insert(mp(min(u,v),max(u,v)));
		}
		else if(v!=p) {
			low[u] = min(low[u], d[v]);
		}
	}
	art[u] = (u ? found : ct>1);
}

//call with FOR0(i,n) if (!visi[i]) dfs(i);

int main() {
	NSYNC;
	return 0;
}
