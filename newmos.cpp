const int MAXN = 100010;
const int BSZ = 350; // ~sqrt(MAXN)
int ans[MAXN], cans;

void add(int pos) {
}

void rem(int pos) {
}

struct node {
	int l, r, idx;
} qrs[MAXN];

void mos(int q) {
	if (!q) return;
	sort(qrs, qrs+q, [](node x, node y) {
		if (x.l/BSZ != y.l/BSZ) return x.l/BSZ < y.l/BSZ;
		return x.r < y.r;
	});
	int cl = qrs[0].l, cr = qrs[0].l;
	FOR0(i,q) {
		int l = qrs[i].l, r = qrs[i].r;
		while(cl < l) rem(cl++);
		while(cl > l) add((cl--)-1);
		while(cr <= r) add(cr++);
		while(cr > r+1) rem((cr--)-1);
		ans[qrs[i].idx] = cans;
	}
}

