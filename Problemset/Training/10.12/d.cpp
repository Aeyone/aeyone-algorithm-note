#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), val(n);
	for(auto &e : a){
		cin >> e;
	}
	auto check = [&](int x, int l, int r)->int{
		int res = 0;
		if(x - l >= 0 && x + r < n){
			res += (a[x] > a[x - l] && a[x] > a[x + r]);
			res += (a[x] < a[x - l] && a[x] < a[x + r]);
		}
		return res;
	};
	int sum = 0;
	for(int i = 0; i < n; i ++){
		sum += check(i, 1, 1);
	}
	int mx = 0;
	for(int i = 0; i < n; i ++){
		int back = check(i - 1, 1, 1) + check(i, 1, 1) + check(i + 1, 1, 1);
		int now = check(i - 1, 1, 2) + check(i + 1, 2, 1);
		if(i - 1 > 0){
			int tmp = a[i];
			a[i] = a[i - 1];
			now = min(now, check(i - 1, 1, 1) + check(i, 1, 1) + check(i + 1, 1, 1));
			a[i] = tmp;
		}
		if(i + 1 < n){
			int tmp = a[i];
			a[i] = a[i + 1];
			now = min(now, check(i - 1, 1, 1) + check(i, 1, 1) + check(i + 1, 1, 1));
			a[i] = tmp;
		}
		mx = max(mx, back - now);
	}
	cout << sum - mx << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}