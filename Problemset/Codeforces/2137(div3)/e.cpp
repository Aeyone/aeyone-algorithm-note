#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), cnt(n + 1);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	int cur = 0;
	for(int i = 0; i <= n; i ++){
		cur += (cnt[i] > 0);
		if(!cnt[i])
			break;
	}
	int mex = 0;
	for(int i = 0; i <= n; i ++){
		mex += (cnt[i] == 1);
		if(cnt[i] != 1)
			break;
	}
	i64 sum = 0;
	if(mex < cur){
		k --;
		for(int i = 0; i < n; i ++){
			if(a[i] < mex || a[i] < cur && cnt[a[i]] == 1)
				continue;
			a[i] = cur;
		}
	}
	for(auto e : a)
		sum += e;
	
	if(k == 0){
		cout << sum << '\n';
		return;
	}
	i64 res = (i64)mex * (mex - 1) / 2;
	if(n - mex > 1){
		if(k & 1)
			cout << res + (i64)(n - mex) * mex << '\n';
		else
			cout << res + (i64)(n - mex) * (mex + 1) << '\n';
	}else{
		cout << (i64)n * (n - 1) / 2 << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}