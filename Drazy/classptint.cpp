struct pt {
  ll x,y;
  pt(): x(0), y(0) {}
  pt(ll x, ll y): x(x), y(y) {}
  pt operator +(pt q){ return pt(x + q.x, y + q.y); }
  pt operator -(pt q){ return pt(x - q.x, y - q.y); }
  ll operator *(pt q){ return x * q.x + y * q.y; }
  ll operator %(pt q){ return x * q.y - y * q.x; }
  bool operator ==(pt q) const { return (x==q.x && y==q.y); }
  bool operator !=(pt q) const { return (x!=q.x || y!=q.y); }
};
ostream& operator<<(ostream& os, const pt& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}