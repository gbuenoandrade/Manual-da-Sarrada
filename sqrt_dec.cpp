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

const int MAXN = 1010;
const int SQRTN = 35;
int v[MAXN];
int blocks[SQRTN + 10];
int n;

void build_sqrt() {
	SET(blocks);
	FOR0(i,n) {
		int b = i/SQRTN;
		if(blocks[b]==-1 || v[i]<v[blocks[b]]) {
			blocks[b] = i;
		}
	}
}

void update_sqrt(int x, int vx) {
	v[x] = vx;
	int b = x/SQRTN;
	if(vx < v[blocks[b]]) blocks[b] = x;
}

int query_sqrt(int x, int y) {
	int ans;
	int minv = INF;
	int i = x;
	while(i<=y && i%SQRTN) {
		if(v[i]<minv) {
			minv = v[i];
			ans = i;
		}
		++i;
	}
	while(i+SQRTN-1 <= y) {
		int b = i/SQRTN;
		if(v[blocks[b]] < minv) {
			minv = v[blocks[b]];
			ans = blocks[b];
		}
		i += SQRTN;
	}
	while(i<=y) {
		if(v[i]<minv) {
			minv = v[i];
			ans = i;
		}
		++i;
	}
	return ans;
}

int main() {
	NSYNC;
	n = 1000;
	set<int> st;
	srand(time(NULL));
	FOR0(i,n) {
		int x;
		while(true) {
			x = rand()%1000000;
			if(!st.count(x)) break;
		}
		st.insert(x);
		v[i] = x;
	}
	build_sqrt();
	int q = 100;
	while(q--) {
		int x = rand()%n;
		int y = rand()%n;
		if(x>y) swap(x,y);
		int minv = INF;
		int ans;
		FOR(i,x,y+1) {
			if(v[i] < minv) {
				minv = v[i];
				ans = i;
			}
		}
		if(ans!=query_sqrt(x,y)) {
			DBGP(mp(x,y));
			DBG(ans);
			DBG(query_sqrt(x,y));
			cout << "WA\n";
			exit(0);
		}
	}
	cout << "Accepted\n";
	return 0;
}