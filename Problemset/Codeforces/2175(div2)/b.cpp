#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, l ,r;
	cin >> n >> l >> r;
	l --, r --;
	vector<int> a(n);
	int pre = 0, cur = 1;
	int L = 0;
	for(int i = 0; i < n; i ++){
		if(i == r){
			a[i] = pre ^ L;
		}else{
			a[i] = pre ^ cur;
		}
		pre ^= a[i];
		cur ++;
		if(i == l - 1){
			L = pre;
		}
	}
	for(auto e : a){
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}