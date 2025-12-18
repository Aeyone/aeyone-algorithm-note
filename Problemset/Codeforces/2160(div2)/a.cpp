#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int mex = 0;
	for(int i = 0; i < n; i ++){
		mex += (a[i] == mex);
	}
	cout << mex << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}