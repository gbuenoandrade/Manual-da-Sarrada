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
typedef vector<int_type> vi;

const int MAXN = 5000;
const int QTD = 2;
int B[] = {31,97};
int MODH[] = {1000000007,1000000009};
int pwr[MAXN][QTD];
int h[MAXN][QTD];
string s;
int n;

void precalc() {
	FOR0(j,QTD) {
		h[0][j] = s[0]%MODH[j];
		pwr[0][j] = 1%MODH[j];
		FOR(i,1,n) {
			h[i][j] = (h[i-1][j]*1LL*B[j] + s[i])%MODH[j];		
			pwr[i][j] = pwr[i-1][j]*1LL*B[j]%MODH[j];
		}
	}
}

void calc(int x, int y, int ans[QTD]) {
	if (x>y) return;
	FOR0(j,QTD) {
		ans[j] = (h[y][j] - (x ? h[x-1][j] : 0)*1LL*pwr[y-x+1][j])%MODH[j];
		if (ans[j] < 0) ans[j] += MODH[j];
	}
}

bool is_eq(int x1, int y1, int x2, int y2) {
	int aux1[QTD], aux2[QTD];
	calc(x1,y1,aux1);
	calc(x2,y2,aux2);
	FOR0(i,QTD) if (aux1[i] != aux2[i]) return false;
	return true;
}

bool is_less(int x1, int y1, int x2, int y2) {
	int sz1 = y1-x1+1, sz2 = y2-x2+1;
	int beg = 0, end = min(sz1,sz2);
	while (beg < end) {
		int mid = (beg+end)/2;
		if (!is_eq(x1,x1+mid, x2, x2+mid)) end = mid;
		else beg = mid + 1;
	}
	if (end == min(sz1,sz2)) return (sz1 < sz2);
	return s[x1+end] < s[x2+end];
}


int main() {
	
	return 0;
}
