#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	bool ok = true;
	for(int i = 1; i <= n; i ++){
		ok &= (a[i - 1] == i || a[i] == i || a[i + 1] == i);
	}
	if(ok){
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