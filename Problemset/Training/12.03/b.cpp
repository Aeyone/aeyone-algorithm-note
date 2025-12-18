#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	vector<int> cnt = {1};
	int cur = 0;
	for(int l = 1, r = 2; l < n; l = r, r ++){
		while(r < n && a[r] > a[r - 1]){
			r ++;
		}
		cur += r - l;
		cnt.back() --;
		if(!cnt.back()){
			cnt.push_back(cur);
			cur = 0;
		}
	}
	cout << cnt.size() - (cur == 0) << '\n';
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