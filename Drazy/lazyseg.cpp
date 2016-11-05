#include <bits/stdc++.h>

using namespace std;
#define DEBUG_ON 1

#define INF 0x3f3f3f3f
#define NSYNC ios::sync_with_stdio(false)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
#define FOR0(i,b) for(int i=0; i<(b); ++i)
#define TRAV(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define RTRAV(it,c) for(__typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); ++it)
#define DBG(x) if(DEBUG_ON) cout << #x << " == " << x << endl
#define DBGP(x) if(DEBUG_ON) cout << "(" << (x).first << ", " << (x).second << ")" << endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define CLR(v) memset(v, 0, sizeof(v))
#define SET(v) memset(v, -1, sizeof(v))
#define R(x) scanf(" %d",&x)
#define RR(x,y) scanf(" %d %d",&x,&y)
#define RRR(x,y,z) scanf(" %d %d %d",&x,&y,&z)

typedef long long ll;
typedef int int_type;
typedef pair<int_type, int_type> pii;
typedef vector<int_type> vi;
typedef vector<vi> vii;

const int MAXN = 40010;
int t[4*2*MAXN];
int lazy[4*2*MAXN];
pii coord[MAXN];
int auxv[2*MAXN];
unordered_set<int> st, stid;

void go(int idx, int v) {
	if(v) {
		t[idx] = v;
		lazy[idx] = v;
	}
}

void shift(int idx) {
	if(lazy[idx]!=0) {
		go(2*idx, lazy[idx]);
		go(2*idx+1, lazy[idx]);
		lazy[idx] = 0;
	}
}

void update(int x, int y, int v, int idx, int l, int r) {
	if(l>y || r<x) return;
	if(l>=x && r<=y) {
		go(idx,v);
		return;
	}
	shift(idx);
	int mid = (l+r)/2;
	update(x,y,v,2*idx,l,mid);
	update(x,y,v,2*idx+1,mid+1,r);
}

int query(int p, int idx, int l, int r) {
	if(p<l || p>r) return 0;
	if(l==r && l==p) {
		return t[idx];
	}
	shift(idx);
	int mid = (l+r)/2;
	return query(p, 2*idx, l, mid) + query(p, 2*idx+1, mid+1,r);
}

int main() {
	int tests;
	R(tests);
	while(tests--) {
		CLR(t);
		CLR(lazy);
		int n;
		R(n);
		int p=0;
		FOR0(i,n) {
			int x,y;
			RR(coord[i].first,coord[i].second);
			auxv[p++] = coord[i].first;
			auxv[p++] = coord[i].second;
		}
		sort(auxv, auxv+p);
		p = unique(auxv, auxv + p) - auxv;
		FOR0(i,n) {
			int x = lower_bound(auxv, auxv+p,coord[i].first) - auxv;
			int y = lower_bound(auxv, auxv+p,coord[i].second) - auxv;
			update(x,y,i+1,1,0,p);
		}
		st.clear();
		FOR0(i,p) {
			int aux = query(i,1,0,p);
			if(aux!=0) st.insert(aux);
		}
		printf("%d\n",(int)st.size());
	}
	return 0;
}