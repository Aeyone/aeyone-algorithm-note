#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;
const int N = 26 * 2e5 + 10;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
int n, tree[N];

void solve() {
	string s;
	cin >> s;
	i64 x;
	cin >> x;
	n = s.size();
	int h = 0, t = -1;
	i64 res = 0;
	map<int, int> mp;
	vector<i64> cnt(26, 0);
	vector<pii> d(26, {1, 0});

	i64 ans = inf;
	for(int i = 0; i < n; i ++){
		d[s[i] - 'a'].second ++;
		mp[s[i] - 'a'] ++;
		for(int j = s[i] - 'a' + 1; j < 26; j ++){
			if(mp[j]){
				int l = d[j].first, r = d[j].second;
				res += (r - l + 1);
				tree[j * n + l] ++;
				tree[j * n + r + 1] --;
			}
		}
		t ++;
		while(res > x && h < t){
			int j = s[h ++] - 'a';
			int l = d[j].first;
			i64 sum = 0;
			for(int k = 1; k <= l; k ++)
				sum += (tree[j * n + k]);
			
			res -= sum;
			ans = min(ans, abs(res - x));
			d[j].first ++;
			mp[j] --;
		}
		ans = min(ans, abs(res - x));
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}