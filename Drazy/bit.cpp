int tree[MAXN];
void update(int idx, int val) {
	while(idx <= n) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
int read(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}



int findG(int cumFre){
    int idx = 0, bitMask = 1;
    for (; (bitMask<<1) <=n; bitMask <<= 1);    
    while ((bitMask != 0) && (idx < n)){
        int tIdx = idx + bitMask;
        if (cumFre >= tree[tIdx]){ 
            idx = tIdx;
            cumFre -= tree[tIdx];
        }
        bitMask >>= 1;
    }
    return (cumFre != 0 ? -1 : idx);
}
