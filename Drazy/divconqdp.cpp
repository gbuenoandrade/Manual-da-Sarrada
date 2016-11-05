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

const int MAXN = 8010;
const ll INFINITE = 1e17;

ll dp[8010][810];
ll v[8010];
int n;

ll cost(int x, int y) {
	if(x>y) return 0;
	ll sum = v[y] - (x ? v[x-1] : 0LL);
	return sum*(y-x+1);
}

void fill(int g, int lmin, int lmax, int pmin, int pmax) {
	if(lmin>lmax) return;
	int lmid = (lmin+lmax)/2;
	dp[lmid][g] = INFINITE;
	ll minp;
	FOR(i,pmin, pmax+1) {
		ll ncost = dp[i][g-1] + cost(i+1,lmid);
		if(ncost < dp[lmid][g]) {
			dp[lmid][g] = ncost;
			minp = i;
		}
	}
	fill(g,lmin,lmid-1,pmin,minp);
	fill(g,lmid+1,lmax,minp,pmax);
}

int main() {
	int g;
	cin >> n >> g;
	FOR0(i,n) {
		cin >> v[i];
		if(i) v[i] += v[i-1];
	}
	FOR0(i,n) {
		dp[i][1] = cost(0,i);
	}
	FOR(i,2,g+1) {
		fill(i,0,n-1,0,n-1);
	}
	cout << dp[n-1][g] << endl;
	return 0;
}