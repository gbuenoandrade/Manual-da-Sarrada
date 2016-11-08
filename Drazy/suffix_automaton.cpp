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

vector<map<char,int>> edges;	// edges[i]  : the labeled edges from node i
vi link;            			// link[i]   : the parent of i
vi length;          			// length[i] : the length of the longest string in the ith class
int last;                    	// the index of the equivalence class of the whole string	
unordered_set<int> terminals;

void build(string s) {
	// add the initial node
	edges.push_back(map<char,int>());
	link.push_back(-1);
	length.push_back(0);
	last = 0;
	FOR0(i, sz(s)){
		// construct r
		edges.push_back(map<char,int>());
		length.push_back(i+1);
		link.push_back(0);
		int r = edges.size() - 1;
		// add edges to r and find p with link to q
		int p = last;
		while(p >= 0 && edges[p].find(s[i]) == edges[p].end()) {
			edges[p][s[i]] = r;
			p = link[p];
		}
		if(p != -1) {
			int q = edges[p][s[i]];
			if(length[p] + 1 == length[q]) {
		  // we do not have to split q, just set the correct suffix link
				link[r] = q;
			}
			else {
				// we have to split, add q'
				edges.push_back(edges[q]); // copy edges of q
				length.push_back(length[p] + 1);
				link.push_back(link[q]); // copy parent of q
				int qq = edges.size()-1;
				// add qq as the new parent of q and r
				link[q] = qq;
				link[r] = qq;
				// move short classes pointing to q to point to q'
				while(p >= 0 && edges[p][s[i]] == q) {
					edges[p][s[i]] = qq;
					p = link[p];
				}
			}
		}
		last = r;
	}
	// finding terminals
	int p = last;
	while(p > 0) {
		terminals.insert(p);
		p = link[p];
	}	
}

int main() {

	return 0;
}
