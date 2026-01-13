#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//高难度双指针
	int n, k;
	cin >> n >> k;
	vector<i64> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	auto query = [&](i64 l, i64 r)->i64{
		return (pre[r] - pre[l - 1]);
	};
	i64 l = k, r = k, lmx = k, rmx = k, sl = 0, sr = 0;
	while(l >= 1 && r <= n){
		bool ok = false;
		while(l >= 1 && query(l, rmx) >= 0){
			ok = true;
			i64 qr = query(l, rmx);
			if(qr > sl){
				sl = qr, lmx = l;
			}
			l --;
		}
		while(r <= n && query(lmx, r) >= 0){
			ok = true;
			i64 qr = query(lmx, r);
			if(qr > sr){
				sr = qr, rmx = r;
			}
			r ++;
		}
		if(!ok){
			break;
		}
	}
	if(l == 0 || r == n + 1){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}