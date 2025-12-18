#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 infll = 0x3f3f3f3f3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	auto f = [&]()->i64{
		vector<i64> pre(n), suf(n);
		int cnt = (s[0] == 'b');
		for(int i = 1; i < n; i ++){
			if(s[i] == 'b'){
				pre[i] = pre[i - 1];
				cnt ++;
			}else{
				pre[i] = pre[i - 1] + cnt;
			}
		}
		cnt = (s[n - 1] == 'b');
		for(int i = n - 2; i >= 0; i --){
			if(s[i] == 'b'){
				suf[i] = suf[i + 1];
				cnt ++;
			}else{
				suf[i] = suf[i + 1] + cnt;
			}
		}
		i64 mn = infll;
		for(int i = 0; i < n; i ++) if(s[i] == 'b'){
			mn = min(mn, pre[i] + suf[i]);
		}
		return mn;
	};
	i64 ans = f();
	for(int i = 0; i < n; i ++){
		s[i] = 'a' + 'b' - s[i];
	}
	ans = min(ans, f());
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}