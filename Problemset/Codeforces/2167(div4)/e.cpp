#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, k, X;
	cin >> n >> k >> X;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> ans(k);
	auto check = [&](int x)->bool{
		int idx = 0;
		for(int l = 0, r = 0, i = 0; i <= n && idx < k; i ++){
			r = (i < n ? a[i] - x : X);
			while(idx < k && l <= r){
				ans[idx ++] = l ++;
			}
			if(i < n){
				l = a[i] + x + (x == 0);
			}
		}
		return (idx == k);
	};
	int l = 0, r = X, res = 0;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			res = mid, l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	check(res);
	for(int i = 0; i < k; i ++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}