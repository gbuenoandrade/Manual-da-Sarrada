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


const double pi = acos(-1);

int cmp(double a, double b = 0){
  if (fabs(a-b)<1e-8) return 0;
  if (a<b) return -1;
  return 1;
}

struct pt {
  double x,y;
  explicit pt(double x = 0, double y = 0): x(x), y(y) {}

  pt operator +(pt q){ return pt(x + q.x, y + q.y); }
  pt operator -(pt q){ return pt(x - q.x, y - q.y); }
  pt operator *(double t){ return pt(x * t, y * t); }
  pt operator /(double t){ return pt(x / t, y / t); }
  double operator *(pt q){ return x * q.x + y * q.y; }
  double operator %(pt q){ return x * q.y - y * q.x; }

  int cmp(pt q) const {
  if (int t = ::cmp(x, q.x)) return t;
  return ::cmp(y, q.y);
  }
  bool operator ==(pt q) const { return cmp(q) == 0; }
  bool operator !=(pt q) const { return cmp(q) != 0; }
  bool operator < (pt q) const { return cmp(q) < 0; }
};

struct reta {
  pt ini,fim;
  reta(){}
  reta(pt ini, pt fim): ini(ini), fim(fim) {}
};

struct eq_reta {
  double A,B,C;  /* Ax + By + C = 0 */

  void init(reta p){
  pt aux = p.ini - p.fim;
  A = aux.y;
  B = -aux.x;
  C = -A*p.ini.x - B*p.ini.y;
  }
  eq_reta(reta p){ init(p); }
};

typedef vector<pt> poly;
typedef pair<pt,double> circ;

pt normal(pt v){ return pt(-v.y,v.x); }
double norma(pt v){ return hypot(v.x, v.y); }
pt versor(pt v){ return v/norma(v); }
double anglex(pt v){ return atan2(v.y, v.x); }
double angle(pt v1, pt v2){ /* angulo orientado ccw */
  return atan2(v1%v2 , v1*v2);
}
double triarea(pt a, pt b, pt c){ /* area c/ sinal */
  return ((b-a)%(c-a))/2.0; /* area>0 = ccw ; area<0 = cw */
}
int ccw(pt a, pt b, pt c){ /* b-a em relacao a c-a */
  return cmp((b-a)%(c-a)); /* ccw=1 ; cw=-1 ; colinear=0 */
  /* equivalente a cmp(triarea(a,b,c)), mas evita divisao */
}
pt projecao(pt v, pt w){ /* proj de v em w */
  double alfa = (v*w)/(w*w);
  return w*alfa;
}

pt pivo;
/* ordena em sentido horario */
bool cmp_radial(pt a, pt b){ 
  int aux = ccw(pivo, a,b);
  return ((aux<0) || (aux==0 && norma(a-pivo)<norma(b-pivo)));
}
bool cmp_pivo(pt p, pt q){ /* pega o de menor x e y */
  int aux = cmp( p.x, q.x );
  return ((aux<0) || (aux==0 && cmp( p.y, q.y )<0));
}
/* usar poly& p reduz tempo, mas desordena o conj de pontos */
poly graham(poly p){
  int i,j,n = p.size();
  poly g;

  /* ordena e torna o conj de pontos um poligono estrelado */
  pivo = *min_element(p.begin(), p.end(), cmp_pivo);
  sort(p.begin(), p.end(), cmp_radial);

   // para pegar colineares do final do poligono
   
  for(i=n-2 ; i>=0 && ccw(p[0], p[i], p[n-1])==0 ; i--);
  reverse(p.begin()+i+1, p.end());
   

  for(i=j=0 ; i<n ; i++) {
   // trocar ccw>=0 por ccw>0 para pegar colineares 
  while( j>=2 && ccw(g[j-2], g[j-1], p[i]) >= 0 ){
    g.pop_back(); j--;
  }
  g.push_back(p[i]); j++;
  }

  return g;
}

/* ponto p entre segmento [qr] */
int between3(pt p, pt q, pt r){
  if(cmp((q-p)%(r-p)) == 0) /* colinear */
  if(cmp((q-p)*(r-p)) <= 0) /* < para nao contar extremos */
    return 1;

  return 0;
}


/* distância de um ponto a uma reta */
double distPR(pt p, reta r){
  pt v = p - r.ini;
  pt w = r.fim - r.ini;

  pt proj = projecao(v,w);
  /* (proj+r.ini) é o ponto mais proximo de p,
   e que pertence à reta r */

   // para segmentos de reta
   
  if( !between3(proj+r.ini, r.ini, r.fim) ) 
    return min( norma(p-r.ini), norma(p-r.fim) );
   

  return norma(v - proj);
}


/* ponto p entre segmento [qr] */
bool iscolin(pt p, pt q, pt r){
  if(cmp((q-p)%(r-p)) == 0) /* colinear */
  return true;
return false;
}

int main() {
  
  return 0;
}