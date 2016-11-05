#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

#define x first
#define y second

typedef pair<int,int> pii;

struct point{
	int x, y, id;
	
	bool operator < (point a) const
	{
		return x < a.x;
	}
};

point p[51234];
point tmp[51234];

double ans = 1e8;
int idx[2];

void update(point i, point j)
{
	double dist = sqrt((i.x-j.x)*1.0*(i.x - j.x) + (i.y-j.y)*1.0*(i.y - j.y)); 
	if(dist < ans)
	{
		ans = dist;
		idx[0] = min(i.id,j.id);
		idx[1] = max(i.id,j.id);
	}
}

bool comp(point a, point b)
{
	return a.y < b.y;
}

int abs(int x) { return x < 0 ? -x : x; }

void solve(int l, int r)
{
	if(r - l <= 3)
	{
		for(int i = l; i <= r; i++)
			for(int j = i + 1; j <= r; j++)
				update(p[i], p[j]);
		sort(p + l, p + r + 1, comp);
		return;
	}
	int mid = (l+r)/2;
	int xmid = p[mid].x, sz = 0;
	solve(l, mid), solve(mid+1, r);
	merge(p + l, p + mid + 1, p + mid + 1, p + r + 1, tmp, comp);
	copy(tmp, tmp + r - l + 1, p + l);
	for(int i = l; i <= r; i++)
		if(abs(p[i].x - xmid) < ans)
		{
			for(int j = sz - 1; j >= 0 && p[i].y - tmp[j].y < ans; j--)
				update(p[i], tmp[j]);
			tmp[sz++] = p[i];
		}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; p[i].id = i, i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	sort(p, p+n);
	solve(0, n-1);
	printf("%d %d %.6lf\n", idx[0], idx[1], ans);
}
