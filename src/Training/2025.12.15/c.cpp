#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {//单调栈好题
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<int> pre(n + 1), b(n + 1, 0);
	for(int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + a[i];
	}
	vector<int> stk;
	for(int i = n; i >= 0; i --) {
		while(stk.size() && pre[stk.back()] > pre[i]) {
			stk.pop_back();
		}
		if(stk.size()) {
			b[i] = b[stk.back()] + (pre[i] - pre[stk.back()]);
		}
		stk.push_back(i);
	}
	stk.clear();
	int mx = 0, num = 0;
	for(int i = 0; i <= n; i ++) {
		if(stk.size() == 0 || pre[i] > stk.back()) {
			if(b[i] > mx) {
				mx = b[i], num = pre[i];
			}
			stk.push_back(pre[i]);
		}
	}
	cout << num << '\n';
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