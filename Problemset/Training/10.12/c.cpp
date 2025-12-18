#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//水题
	int n;
	cin >> n;
	vector<int> k(n), h(n);
	for(int i = 0; i < n; i ++){
		cin >> k[i];
	}
	for(int i = 0; i < n; i ++){
		cin >> h[i];
	}
	vector<array<int, 2>> seg, res;
	for(int i = 0; i < n; i ++){
		seg.push_back({k[i] - h[i] + 1, k[i]});
	}
	sort(seg.begin(), seg.end());
	int st = -1, ed = -1;
	for(auto [l, r] : seg){
		if(l > ed){
			if(ed != -1){
				res.push_back({st, ed});
			}
			st = l, ed = r;
		}else{
			ed = max(ed, r);
		}
	}
	res.push_back({st, ed});
	i64 ans = 0;
	for(auto [l, r] : res){
		i64 d = r - l + 1;
		ans += d * (d + 1) / 2;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}