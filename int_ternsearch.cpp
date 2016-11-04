
#max

int lo = -1, hi = n;
while (hi - lo > 1){
	int mid = (hi + lo)>>1;
	if (f(mid) > f(mid + 1)) 
		 hi = mid;
	else 
		 lo = mid; 
}
ans = lo + 1
		
