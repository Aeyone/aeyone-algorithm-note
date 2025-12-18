#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), u(n), d(n);
	i64 mn = 0, mx = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(a[i] > 0){
			d[i] = ((double)(a[i] - 1) + 0.5) * 1e7;
		}else{
			d[i] = a[i] * 1e7;
		}
		if(a[i] < 100){
			u[i] = ((double)a[i] + 0.5) * 1e7 - 1;
		}else{
			u[i] = a[i] * 1e7;
		}
		mn += d[i], mx += u[i];
	}
	if(mn > 1e9 || mx < 1e9){
		cout << "No" << '\n';
		return;
	}
	int dis = 1e9 - mn;
	cout << "Yes" << '\n';
	for(int i = 0; i < n; i ++){
		if(d[i] + dis < u[i]){
			d[i] += dis;
			dis = 0;
			break;
		}else{
			dis -= u[i] - d[i];
			d[i] = u[i];
		}
	}
	i64 sum = 0;
	for(int i = 0; i < n; i ++){
		cout << d[i] << ' ';
		sum += d[i];
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