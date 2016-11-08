#include <bits/stdc++.h>

using namespace std;
#define DEBUG_ON 1

#define INF 0x3f3f3f3f
#define NSYNC ios::sync_with_stdio(false)
#define FOR(i,a,b) for(int i=a; i<(b); ++i)
#define FOR0(i,b) for(int i=0; i<(b); ++i)
#define TRAV(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define RTRAV(it,c) for(__typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); ++it)
#define DBG(x) if(DEBUG_ON) cout << #x << " == " << x << endl
#define DBGP(x, y) if(DEBUG_ON) cout << "(" << x << ", " << y << ")" << endl
#define DBGV(v) if(DEBUG_ON) for (auto x : (v)) cout << x << " "; cout << endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(a) (int)((a).size())
#define all(c) (c).begin(),(c).end()
#define R(x) scanf(" %d",&(x))
#define RR(x,y) scanf(" %d %d",&(x), &(y))
#define CLR(v) memset(v, 0, sizeof(v))
#define SET(v) memset(v, -1, sizeof(v))

typedef long long ll;
typedef int int_type;
typedef pair<int_type, int_type> pii;
typedef pair<ll,ll> pll;
typedef vector<int_type> vi;

typedef long double ld;
struct node {
	ld left, p, q;
};
vector<node> lines;

ld get_inter(ld p, ld q, ld r, ld s) { return (q-s)/(r-p); }

// lines must be inserted in strictly decreasing order of p
void insert(ld p, ld q) {
	while (sz(lines) >= 2) {
		ld r = lines[sz(lines)-2].p;
		ld s = lines[sz(lines)-2].q;
		if (lines.back().left > get_inter(p,q,r,s)) lines.pop_back();
		else break;
	}
	node nd;
	nd.p = p; nd.q = q;
	nd.left = (lines.empty() ? -INFINITY : get_inter(lines.back().p, lines.back().q, p, q));
	lines.pb(nd);
}

ld get_min(ld x) {
	node aux;
	aux.left = x;
	auto nd = *prev(upper_bound(all(lines), aux, [](node a, node b){ return a.left < b.left; }));
	return nd.p*x + nd.q;
}

int main() {
	return 0;
}
