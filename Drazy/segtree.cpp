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

const int MAXN = 110;
int tree[4*MAXN];
int v[MAXN];

void build(int idx, int l, int r) {
	if(l==r) {
		tree[idx] = v[l];
	}
	else {
		int m = (l+r)/2;
		build(2*idx,l,m);
		build(2*idx+1,m+1,r);
		tree[idx] = tree[2*idx] + tree[2*idx+1];
	}
}

void update(int p, int val, int idx, int l, int r) {
	if(l==r) {
		tree[idx] = val;
	}
	else {
		int m = (l+r)/2;
		if(p>=l && p<=m) update(p,val,2*idx,l,m);
		else update(p,val,2*idx+1,m+1,r);
		tree[idx] = tree[2*idx] + tree[2*idx+1];
	}
}

int query(int px, int py, int idx, int l, int r) {
	if(py<l || px>r) {
		return 0;
	}
	if(l>=px && r<=py) {
		return tree[idx];
	}
	int m = (l+r)/2;
	int p1 = query(px,py,2*idx,l,m);
	int p2 = query(px,py,2*idx+1,m+1,r);
	return p1+p2;
}

int main() {
	NSYNC;
	return 0;
}