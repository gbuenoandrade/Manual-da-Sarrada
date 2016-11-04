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

const int MAXN = 200010;
const int LOGMAXN = 20;
int p[LOGMAXN][MAXN];
int sa[MAXN];
int step;
pair<pii,int> vaux[MAXN];
string s;

void calcsa() {
	int n = s.size();
	FOR0(i,n) p[0][i] = s[i];
	if(n==1) p[0][0] = 0;	
	int pot;
	for(step=1,pot=2; pot<2*n; ++step, pot*=2) {
		FOR0(i,n) {
			vaux[i].first.first = p[step-1][i];
			vaux[i].first.second =  (i+pot/2 < n ? p[step-1][i+pot/2] : -1); 
			vaux[i].second = i;
		}
		sort(vaux,vaux+n);
		int id = 0;
		FOR0(i,n) {
			if(i && vaux[i].first != vaux[i-1].first) ++id;
			p[step][vaux[i].second] = id;
		}
	}
	--step;
	FOR0(i,n) {
		sa[p[step][i]] = i;
	}	
}

int lcp(int x, int y) {
	int n = s.size();
	if(x==y) return n-x;
	int ans = 0;
	for(int i=step; i>=0; --i) {
		if(p[i][x]==p[i][y]) {
			ans |= (1<<i);
			x += (1<<i);
			y += (1<<i);
			if(x>=n || y>=n) break;
		}
	}
	return ans;
}

int main() {
	NSYNC;
	cin >> s;
	reverse(s.begin(),s.end());
	calcsa();
	int q;
	cin >> q;
	int n = s.size();
	while(q--) {
		int x;
		cin >> x;
		cout << lcp(0,n-x) << endl;
	}
	return 0;
}