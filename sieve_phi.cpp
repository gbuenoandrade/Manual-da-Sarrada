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


const int MAXN = 10000010;
int pr[MAXN];
int divisor[MAXN];
int phi[MAXN];

void sieve(int n) {
	FOR0(i,n+1) pr[i] = true;
	pr[0] = pr[1] = false;
	for(int i=2; i*i<=n; ++i) {
		if(!pr[i]) continue;
		int k = i*i;
		while(k<=n) {
			divisor[k] = i;
			pr[k] = false;
			k += i;
		}
	}
}

void calc_phi(int n) {
	FOR(i,1,n+1) phi[i] = i;
	FOR(i,2,n+1) if(pr[i]) {
		for(int j=i; j<=n; j+=i) {
			phi[j] -= phi[j]/i;
		}
	}
}

inline int get_div(int n) {
	if(pr[n]) return n;
	return divisor[n];
}

int factorize(int v[], int n) {
	if(n<=1) return 0;	
	int sz=0;
	while(n>1) {
		int p = get_div(n);
		v[sz++] = p;
		n/=p;
	}
	return sz;
}


int main() {
	sieve(1000);
	calc_phi(100);
	DBG(phi[80]);
	DBG(phi[77]);
	DBG(phi[50]);
	// DBG(phi(80));
	// FOR(i,1,11) cout << "phi(" << i << ") = " << phi[i] << endl;
	return 0;
}