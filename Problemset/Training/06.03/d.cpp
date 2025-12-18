#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, l;
	cin >> n >> l;
	vector<int> a(n + 2, 0);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	a[n + 1] = l;

	vector<double> t1(n + 2, 0), t2(n + 2, 0);
	for(int i = 1; i <= n + 1; i ++){
		double d = a[i] - a[i - 1];
		t1[i] = t1[i - 1] + d / i;
	}
	for(int i = n; i >= 0; i --){
		double d = a[i + 1] - a[i];
		t2[i] = t2[i + 1] + d / (n - i + 1);
	}
	int mid = 0;
	while(t1[mid] < t2[mid])
		mid ++;

	double va = mid, vb = n - mid + 2;
	double d = a[mid] - a[mid - 1];
	double res = 0;
	if(t1[mid - 1] >= t2[mid])
		d -= vb * (t1[mid - 1] - t2[mid]), res += t1[mid - 1];
	if(t1[mid - 1] < t2[mid])
		d -= va * (t2[mid] - t1[mid - 1]), res += t2[mid];
	res += d / (va + vb);
	printf("%.8f\n", res);
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	// ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}