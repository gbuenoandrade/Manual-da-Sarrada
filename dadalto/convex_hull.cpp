//http://www.spoj.com/problems/GARDENHU/

#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define inf 0x3f3f3f3f

class point{

public:
	long long x, y;
	
	point(long long _x = 0, long long _y = 0) : x(_x), y(_y)
	{}
	
	long long cross(point p1, point p2)
	{
		return (p1.x - x)*(p2.y - y) - (p2.x - x)*(p1.y - y);
	}
	
	
} p[112345];

bool comp(point a, point b)
{
	return p[0].cross(a, b) > 0;
}

double dist(point a, point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

point ch[112345];

int
main(void)
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld %lld", &p[i].x, &p[i].y);
	
	for(int i = 1; i < n; i++)
		if(p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x))
			swap(p[0], p[i]);
	
	sort(p+1, p+n, comp);

	ch[0] = p[0], ch[1] = p[1];
	int nch = 2;
	for(int i = 2; i < n; i++)
	{
		while(ch[nch-2].cross(ch[nch-1], p[i]) <= 0)
			nch--;
		ch[nch++] = p[i];
	}
	double ans = 0.0;
	for(int i = 0; i < nch; i++)
		ans += dist(ch[i], ch[(i+1)%nch]);
	printf("%lld\n", (long long) ans);
}












