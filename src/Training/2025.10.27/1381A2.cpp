#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//双指针
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	a = "x" + a, b = "x" + b;
	vector<int> ans;
	for(int l = 1, r = 1; l <= n; l = r){
		while(r <= n && a[r] == a[l]){
			r ++;
		}
		if(r <= n){
			ans.push_back(r - 1);
		}
	}
	int cur = (a.back() == '1');
	for(int i = n; i >= 1; i --){
		if(b[i] - '0' != cur){
			ans.push_back(i);
			cur ^= 1;
		}
	}
	cout << ans.size() << ' ';
	for(auto e : ans){
		cout << e << ' ';
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